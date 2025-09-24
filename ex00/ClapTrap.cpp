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


/* Orthodox Canonical Form */


ClapTrap::ClapTrap( void ) : 
	_name("name"), 
	_hitPoints(10),
	_energyPoints(10), 
	_attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}


ClapTrap::ClapTrap( std::string name ) : 
	_name(name), 
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cout << "Attribution constructor called" << std::endl;
}


ClapTrap::ClapTrap( ClapTrap const & src ) : 
	_name(src._name), 
	_hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints),
		_attackDamage(src._attackDamage) {
	std::cout << "Copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=( ClapTrap const & src ) {
	if ( DEBUG )
	std::cout << "assignation operator called" << std::endl;
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return ( *this );
}


ClapTrap::~ClapTrap( void ) {
	std::cout << "Destructor called" << std::endl;
}


/* needed functions */


void ClapTrap::attack( const std::string& target ) {
	std::cout << "[ hp:" << _hitPoints << "\tep:" << _energyPoints << " ]\t";
	if (_hitPoints == 0) {
		std::cout << RED << "ClapTrap " << _name 
				<< " can't attack because he has no hit point left" << RESET << std::endl;
	}
	else if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << PURPLE << "ClapTrap " << _name << " attacks " << target << RESET << std::endl;
	}
	else
		std::cout << YELLOW << "ClapTrap " << _name << " has no energy left to attack" << RESET << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "[ hp:" << _hitPoints << "\tep:" << _energyPoints << " ]\t";
	if (_hitPoints == 0) 
		std::cout << RED << "ClapTrap " << _name << "'s hp is already 0, please stop beating it" 
				<< RESET << std::endl;
	else if (_hitPoints > amount) {
		_hitPoints -= amount;
		std::cout << RED << "ClapTrap " << _name << " takes " << amount << " damage" << RESET << std::endl;
	}
	else {
		_hitPoints = 0;
		std::cout << RED << "ClapTrap " << _name << " takes " << amount << " damage and dies from it's injuries" 
				<< RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "[ hp:" << _hitPoints << "\tep:" << _energyPoints << " ]\t";
	if (_hitPoints == 0)
		std::cout << RED << "ClapTrap " << _name << " is dead and cannot repair itself" << RESET << std::endl;
	else if (_energyPoints > 0 && _hitPoints < 10 && amount + _hitPoints < 10) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << CYAN << "ClapTrap " << _name << " repaired itself by " << amount << " hit points"
				<< RESET << std::endl;
	}
	else if (_energyPoints > 0 && _hitPoints < 10 && amount + _hitPoints >= 10) {
		_energyPoints--;
		std::cout << CYAN << "ClapTrap " << _name << " repaired itself by " << 10 - _hitPoints << " hit points and has reach full hp"
				<< RESET << std::endl;
		_hitPoints = 10;
	}
	else if (_energyPoints > 0 && _hitPoints == 10)
		std::cout << CYAN << "ClapTrap " << _name << " is already at full hp and don't need repair" << RESET << std::endl;
	else
		std::cout << YELLOW << "ClapTrap " << _name << " has no energy left to repair itself" << RESET << std::endl;
}