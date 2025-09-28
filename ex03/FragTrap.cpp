/* *************************************************************************************************************** */
/*   FragTrap.cpp                                                                                                  */
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

#include "FragTrap.hpp"

#define READY		"is happy and ready to attack"
#define CLONED		"has been cloned and is ready to attack"
#define FINISH		"has successfully destroyed the target"
#define COOL		"request to do a high five"


#define SCAV_PREFIX(color, name)	color << "FragTrap \"" << name << "\" "
#define STATUS(hp, energy)			"[ hp:" << hp << " ep:" << energy << " ] "

/* ===================== Orthodox Canonical Form ====================== */


FragTrap::FragTrap( void ) : 
	ClapTrap() {
	_hitPoints = HP_MAX;
	_energyPoints = 100;
	_attackDamage = 30;
	_buffHitPoints = _hitPoints;
	_buffEnergyPoints = _energyPoints;
	_buffAttackDamage = _attackDamage;
	std::cout << SCAV_PREFIX(WHITE, _name) << READY << RESET << std::endl;
}


FragTrap::FragTrap( std::string name ) : 
	ClapTrap( name ) {
	_buffHitPoints = HP_MAX;
	_buffEnergyPoints = 100;
	_buffAttackDamage = 30;
	std::cout << "\e[1;97mCustom " << SCAV_PREFIX(WHITE, _name) << READY << RESET << std::endl;
}


FragTrap::FragTrap( FragTrap const & src ) : 
	ClapTrap( src ) {
	std::cout << SCAV_PREFIX(WHITE, _name) << CLONED << RESET << std::endl;
}


FragTrap::~FragTrap( void ) {
	std::cout << SCAV_PREFIX(WHITE, _name) << FINISH << RESET << std::endl;
}


FragTrap& FragTrap::operator=( FragTrap const & src ) {
	if (&src != this)
	{
		if ( DEBUG )
			std::cout << WHITE << "Cloning..." << RESET << std::endl;
		_name = src._name;
		_buffHitPoints = src._buffHitPoints;
		_buffEnergyPoints = src._buffEnergyPoints;
		_buffAttackDamage = src._buffAttackDamage;
	}
	return ( *this );
}


/* =========================== needed functions ============================ */


void	FragTrap::highFivesGuys( void ) {

	std::cout << STATUS(getHitPoints(), getEnergy());

	std::cout << SCAV_PREFIX(PURPLE, _name) << COOL << RESET << std::endl;
}

