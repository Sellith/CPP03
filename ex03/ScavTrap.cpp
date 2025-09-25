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
#define FINISH		"has successfully defended the target"
#define GATE		"activated gate keeper mode"
#define	NODEF		"can't defend because he has no hit point left" 
#define COUNTER		"counter-attacks from "
#define	NOEDEF		"has no energy left to defend"


#define SCAV_PREFIX(color, name)	color << "ScavTrap \"" << name << "\" "
#define STATUS(hp, energy)			"[ hp:" << hp << " ep:" << energy << " ] "

/* ===================== Orthodox Canonical Form ====================== */


ScavTrap::ScavTrap( void ) : 
	ClapTrap() {
	_hitPoints = HP_MAX;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << SCAV_PREFIX(WHITE, getName()) << READY << RESET << std::endl;
}


ScavTrap::ScavTrap( std::string name ) : 
	ClapTrap( name ) {
	_hitPoints = HP_MAX;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\e[1;97mCustom " << SCAV_PREFIX(WHITE, getName()) << READY << RESET << std::endl;
}


ScavTrap::ScavTrap( ScavTrap const & src ) : 
	ClapTrap( src ) {
	std::cout << SCAV_PREFIX(WHITE, _name) << CLONED << RESET << std::endl;
}


ScavTrap::~ScavTrap( void ) {
	std::cout << SCAV_PREFIX(WHITE, _name) << FINISH << RESET << std::endl;
}


/* =========================== needed functions ============================ */


void	ScavTrap::guardGate( void ) {

	std::cout << STATUS(getHitPoints(), getEnergy());

	std::cout << SCAV_PREFIX(PURPLE, _name) << GATE << RESET << std::endl;
}


void    ScavTrap::attack( const std::string & target ) {

	std::cout << STATUS(getHitPoints(), getEnergy());

	if (getHitPoints() == 0) {
		std::cout << SCAV_PREFIX(RED, _name) 
				<< NODEF << RESET << std::endl;
	}

	else if (getEnergy() > 0) {
		setEnergy(getEnergy() - 1);
		std::cout << SCAV_PREFIX(PURPLE, _name) 
				<< COUNTER << target << RESET << std::endl;
	}

	else
		std::cout << SCAV_PREFIX(YELLOW, _name) 
				<< NOEDEF << RESET << std::endl;
}
