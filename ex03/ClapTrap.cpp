/* *************************************************************************************************************** */
/*                                                                                  .,                             */
/*                                                                                 okxl                            */
/*                                                                                xkddo                            */
/*                                                                               kkxddo                            */
/*                                                                              lxxddol                            */
/*                                                                              xxdolol.                           */
/*                                                                             :kxdddddl                 .ox,      */
/*                                                                       ..,cdkOOkkkxdddd'      ;o.     ckkd,      */
/*                                                               .,:coxOOOkkkkkkkxxxxxddddo:...lxdl.   ckkxd.      */
/*   ClapTrap.cpp                                            ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
/*                                                        ,oOOOkkkkxxxdddxdddddddddddddoooooodooddddooooddooc      */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr>       ;kkkkkxxxxxddoooooooooooooooooooooooooollooooooololll      */
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


#include "ClapTrap.hpp"

#define CT_PREFIX(color, name)		color << "ClapTrap \"" << name << "\" "

/* ===================== Orthodox Canonical Form ====================== */


ClapTrap::ClapTrap( void ) : 
	_name( "Random" ), 
	_hitPoints(10),
	_energyPoints(10), 
	_attackDamage(0) {
	std::cout << CT_PREFIX(WHITE, _name) << "is created" << RESET << std::endl;
}


ClapTrap::ClapTrap( std::string name ) : 
	_name( name ), 
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cout << "\e[1;97mCustom " << CT_PREFIX(WHITE, _name) << "is created" << RESET << std::endl;
}


ClapTrap::ClapTrap( ClapTrap const & src ) : 
	_name(src._name), 
	_hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints),
		_attackDamage(src._attackDamage) {
	std::cout << CT_PREFIX(WHITE, _name) << "has been cloned" << std::endl;
}


ClapTrap& ClapTrap::operator=( ClapTrap const & src ) {
	if (&src != this)
	{
		if ( DEBUG )
			std::cout << "Cloning..." << std::endl;
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return ( *this );
}


ClapTrap::~ClapTrap( void ) {
	std::cout << CT_PREFIX(WHITE, _name) << "is destroyed" << std::endl;
}


/* =========================== needed functions ============================ */


void ClapTrap::attack( const std::string& target ) {
	std::cout << "[ hp:" << _hitPoints << " ep:" << _energyPoints << " ] ";
	if (_hitPoints == 0) {
		std::cout << RED << "ClapTrap " << _name 
				<< " can't attack because he has no hit point left" 
				<< RESET << std::endl;
	}
	else if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << PURPLE << "ClapTrap " << _name 
		<< " attacks " << target << RESET << std::endl;
	}
	else
		std::cout << YELLOW << "ClapTrap " << _name 
		<< " has no energy left to attack" << RESET << std::endl;
}



void    ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "[ hp:" << _hitPoints - amount << " ep:" << _energyPoints << " ] ";
	if (_hitPoints == 0) 
		std::cout << RED << "ClapTrap " << _name 
				<< "'s hp is already 0, please stop beating it" 
				<< RESET << std::endl;
	else if (_hitPoints > amount) {
		_hitPoints -= amount;
		std::cout << RED << "ClapTrap " << _name << " takes " 
				<< amount << " damage" << RESET << std::endl;
	}
	else {
		_hitPoints = 0;
		std::cout << RED << "ClapTrap " << _name << " takes " 
				<< amount << " damage and dies from it's injuries" 
				<< RESET << std::endl;
	}
}



void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "[ hp:" << _hitPoints << " ep:" << _energyPoints << " ] ";
	if (_hitPoints == 0)
		std::cout << RED << "ClapTrap " << _name << " is dead and cannot repair itself"
				<< RESET << std::endl;
	else if (_energyPoints > 0 && _hitPoints < HP_MAX && amount + _hitPoints < HP_MAX) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << CYAN << "ClapTrap " << _name << " repaired itself by " 
				<< amount << " hit points" << RESET << std::endl;
	}
	else if (_energyPoints > 0 && _hitPoints < HP_MAX && amount + _hitPoints >= HP_MAX) {
		_energyPoints--;
		std::cout << CYAN << "ClapTrap " << _name << " repaired itself by " 
				<< HP_MAX - _hitPoints << " hit points and has reach full hp"
				<< RESET << std::endl;
		_hitPoints = HP_MAX;
	}
	else if (_energyPoints > 0 && _hitPoints == HP_MAX)
		std::cout << CYAN << "ClapTrap " << _name 
				<< " is already at full hp and don't need repair" 
				<< RESET << std::endl;
	else
		std::cout << YELLOW << "ClapTrap " << _name 
				<< " has no energy left to repair itself" 
				<< RESET << std::endl;
}


/* =========================== getter functions ============================ */


std::string	ClapTrap::getName() {
	return (_name);
}

unsigned int	ClapTrap::getAttack() {
	return (_attackDamage);
}

unsigned int	ClapTrap::getHitPoints() {
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergy() {
	return (_energyPoints);
}


/* =========================== setter functions ============================ */


void	ClapTrap::setName( std::string newName ) {
	_name = newName;
	return ;
}

void	ClapTrap::setAttack( unsigned int newAp ) {
	_attackDamage = newAp;
	return ;
}

void	ClapTrap::setHitPoints( unsigned int newHp ) {
	_hitPoints = newHp;
	return ;
}

void	ClapTrap::setEnergy( unsigned int newEp ) {
	_energyPoints = newEp;
	return ;
}