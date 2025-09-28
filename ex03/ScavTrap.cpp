/* *************************************************************************************************************** */
/*   ScavTrap.cpp                                                                                                  */
/*   By: lvan-bre                                                                   .,                             */
/*                                                                                 okxl                            */
/*                                                                                xkddo                            */
/*                                                                               kkxddo                            */
/*                                                                              lxxddol                            */
/*                                                                              xxdolol.                           */
/*                                                                             :kxdddddl                 .ox,      */
/*                                                                       ..,cdkOOkkkxdddd'      ;o.     ckkd,      */
/*                                                               .,:coxOOOkkkkkkkxxxxxddddo:...lxdl.   ckkxd.      */
/*                                                           ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
/*                                                        ,oOOOkkkkxxxdddxdddddddddddddoooooodooddddooooddooc      */
/*                                                      ;kkkkkxxxxxddoooooooooooooooooooooooooollooooooololll      */
/*                                                     oxodddddoooooolllllllolooooollloooollllolllllloooolccl;     */
/*                                                    'x:::cclccllllccccccccccclllclllllllllllllllll     .;;cl;    */
/*                                                    d;c::cc:cc:::;::c:c:cccccclccc:cccclllllll,         .:cl.    */
/*                                                      c;,;:;;::::;;::::c..,cccllcc:c;;:lloodk.                   */
/*                                                        'ooooooooodddxxkkkOOOkOOOOOOc:cclllloo'                  */
/*                                                           .XXXXXXXKKXXXXXXXXXXXXXXXkcccclcccllo                 */
/*                                                                 ,KKKKKXXXXXXXXXXXXK0.  .:ccllclll;.             */
/*                                                                                           .ccccccllc,.          */
/*                                                                                                 :::cl:          */
/*                                                                                                                 */
/* *************************************************************************************************************** */

#include "ScavTrap.hpp"

#define READY		"is ready to defend"
#define CLONED		"has been cloned and is ready to defend"
#define FINISH		"has successfully defended target"
#define GATE		"activated gate keeper mode"
#define DEADGATE	"couldn't activate gate keeper mode, as he has no hit points left"
#define NOGATE		"'s gate keeper mode is already activated"
#define	NODEF		"can't defend because he has no hit point left" 
#define COUNTER		"counter-attacks from "
#define	NOEDEF		"has no energy left to defend"
#define DEADGUARD	"gate keeper mode is deactivated"


#define SCAV_PREFIX(color, name)	color << "ScavTrap \"" << name << "\" "
#define STATUS(hp, energy)			"[ hp:" << hp << " ep:" << energy << " ] "

/* ===================== Orthodox Canonical Form ====================== */


ScavTrap::ScavTrap( void ) : 
	ClapTrap(), _guardstatus(false) {
	_hitPoints = HP_MAX;
	_energyPoints = 50;
	_attackDamage = 20;
	_buffHitPoints = _hitPoints;
	_buffEnergyPoints = _energyPoints;
	_buffAttackDamage = _attackDamage;
	std::cout << SCAV_PREFIX( WHITE, getName() ) << READY << RESET << std::endl;
}


ScavTrap::ScavTrap( std::string name ) : 
	ClapTrap( name ), _guardstatus(false) {
	_hitPoints = HP_MAX;
	_energyPoints = 50;
	_attackDamage = 20;
	_buffHitPoints = _hitPoints;
	_buffEnergyPoints = _energyPoints;
	_buffAttackDamage = _attackDamage;
	std::cout << "\e[1;97mCustom " << SCAV_PREFIX( WHITE, getName() ) << READY << RESET << std::endl;
}


ScavTrap::ScavTrap( ScavTrap const & src ) : 
	ClapTrap( src ), _guardstatus(src._guardstatus) {
	std::cout << SCAV_PREFIX( WHITE, getName() ) << CLONED << RESET << std::endl;
}


ScavTrap::~ScavTrap( void ) {
	std::cout << SCAV_PREFIX( WHITE, getName() ) << FINISH << RESET << std::endl;
}


ScavTrap& ScavTrap::operator=( ScavTrap const & src ) {
	if (&src != this)
	{
		if ( DEBUG )
			std::cout << WHITE << "Cloning..." << RESET << std::endl;
		_name = src._name;
		_buffHitPoints = src._buffHitPoints;
		_buffEnergyPoints = src._buffEnergyPoints;
		_buffAttackDamage = src._buffAttackDamage;
		_guardstatus = src._guardstatus;
	}
	return ( *this );
}


/* =========================== needed functions ============================ */


void	ScavTrap::guardGate( void ) {

	std::cout << STATUS( getHitPoints(), getEnergy() );

	if (_hitPoints == 0)
		std::cout << SCAV_PREFIX( YELLOW, getName() ) << DEADGATE << RESET << std::endl;
	else
	{
		if (!_guardstatus)
		{
			std::cout << SCAV_PREFIX( CYAN, getName() ) << GATE << RESET << std::endl;
			_guardstatus = true;
		}
		else
			std::cout << SCAV_PREFIX( YELLOW, getName() ) << NOGATE << RESET << std::endl;
	}
}


void	ScavTrap::attack( const std::string& target ) {

	std::cout << STATUS( getHitPoints(), getEnergy() );

	if (getHitPoints() == 0) {
		std::cout << SCAV_PREFIX( RED, getName() ) 
				<< NODEF << RESET << std::endl;
	}

	else if (getEnergy() > 0) {
		setEnergy(getEnergy() - 1);
		std::cout << SCAV_PREFIX( PURPLE, getName() ) 
				<< COUNTER << target << RESET << std::endl;
	}

	else
		std::cout << SCAV_PREFIX( YELLOW, getName() ) 
				<< NOEDEF << RESET << std::endl;
}


void    ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) 
	{
		std::cout << STATUS( getHitPoints(), getEnergy() );
		std::cout << RED << "ScavTrap " << _name 
				<< "'s hp is already 0, please stop beating it" 
				<< RESET << std::endl;
		return ;
	}
	if (_hitPoints > amount) {
		_hitPoints -= amount;
		std::cout << STATUS( getHitPoints(), getEnergy() );
		std::cout << RED << "ScavTrap " << _name << " takes " 
				<< amount << " damage" << RESET << std::endl;
	}
	else {
		_hitPoints = 0;
		std::cout << STATUS( getHitPoints(), getEnergy() );
		std::cout << RED << "ScavTrap " << _name << " takes " 
				<< amount << " damage and dies from it's injuries" 
				<< RESET << std::endl;
		if (_guardstatus)
		{
			std::cout << STATUS( getHitPoints(), getEnergy() );
			_guardstatus = false;
			std::cout << SCAV_PREFIX( YELLOW, getName() ) << DEADGUARD << RESET << std::endl;
		}
	}
}
