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
#define	NODEF		"can't defend because he has no hit point left" 
#define COUNTER		"counter-attacks from "
#define	NOEDEF		"has no energy left to defend"
#define PITY		"'s hp is already 0, please stop beating it" 
#define ISDEAD		" damage and dies from it's injuries" 
#define ISTOODEAD	"is dead and cannot repair itself"
#define REPAIRED	"repaired itself by " 
#define FULL		" hit points and has reach full hp"
#define FULL_HP		"is already at full hp and don't need repair"
#define NOEREP		"has no energy left to repair itself"

#define SCAV_PREFIX(color, name)	color << "ScavTrap \"" << name << "\" "
#define STATUS(hp, energy)			"[ hp:" << hp << " ep:" << energy << " ] "

/* ===================== Orthodox Canonical Form ====================== */


ScavTrap::ScavTrap( void ) : 
	ClapTrap(),
    _gateKeeperMode( false ) {
	std::cout << SCAV_PREFIX(WHITE, getName()) << READY << RESET << std::endl;
}


ScavTrap::ScavTrap( std::string name ) : 
	ClapTrap( name ),
    _gateKeeperMode(false) {
	std::cout << "\e[1;97mCustom " << SCAV_PREFIX(WHITE, getName()) << READY << RESET << std::endl;
}


ScavTrap::ScavTrap( ScavTrap const & src ) : 
	ClapTrap( src ),
    _gateKeeperMode(src._gateKeeperMode) {
	std::cout << SCAV_PREFIX(WHITE, getName()) << CLONED << RESET << std::endl;
}


ScavTrap::~ScavTrap( void ) {
	std::cout << SCAV_PREFIX(WHITE, getName()) << FINISH << RESET << std::endl;
}


/* =========================== needed functions ============================ */


void	ScavTrap::guardGate( void ) {

	std::cout << STATUS(getHitPoints(), getEnergy());

    std::cout << SCAV_PREFIX(PURPLE, getName()) << GATE << RESET << std::endl;
    _gateKeeperMode = true;
}


void    ScavTrap::attack( const std::string& target ) {

	std::cout << STATUS(getHitPoints(), getEnergy());

	if (getHitPoints() == 0) {
		std::cout << SCAV_PREFIX(RED, getName()) 
                << NODEF << RESET << std::endl;
	}

	else if (getEnergy() > 0) {
		setEnergy(getEnergy() - 1);
		std::cout << SCAV_PREFIX(PURPLE, getName()) 
                << COUNTER << target << RESET << std::endl;
	}

	else
		std::cout << SCAV_PREFIX(YELLOW, getName()) 
                << NOEDEF << RESET << std::endl;
}


void    ScavTrap::takeDamage(unsigned int amount) {

	std::cout << STATUS(getHitPoints(), getEnergy());

	if (getHitPoints() == 0) 
		std::cout << SCAV_PREFIX(RED, getName()) 
                << PITY << RESET << std::endl;

	else if (getHitPoints() > amount) {
		setHitPoints(getHitPoints() - amount);
		std::cout << SCAV_PREFIX(RED, getName()) << "takes " 
				<< amount << " damage" << RESET << std::endl;
	}

	else {
		setHitPoints(0);
		std::cout << SCAV_PREFIX(RED, getName()) << "takes " 
				<< amount << ISDEAD << RESET << std::endl;
	}
}


void	ScavTrap::beRepaired(unsigned int amount) {
	
	std::cout << STATUS(getHitPoints(), getEnergy());

	if (getHitPoints() == 0)
		std::cout << SCAV_PREFIX(RED, getName()) << ISTOODEAD
				<< RESET << std::endl;

	else if (getEnergy() > 0 && getHitPoints() < HP_MAX && amount + getHitPoints() < HP_MAX) {
		setEnergy(getEnergy() - 1);
		setHitPoints(getHitPoints() + amount);
		std::cout << SCAV_PREFIX(CYAN, getName()) << REPAIRED
				<< amount << " hit points" << RESET << std::endl;
	}

	else if (getEnergy() > 0 && getHitPoints() < HP_MAX && amount + getHitPoints() >= HP_MAX) {
		setEnergy(getEnergy() - 1);
		std::cout << SCAV_PREFIX(CYAN, getName()) << REPAIRED
				<< HP_MAX - getHitPoints() << FULL << RESET << std::endl;
		setHitPoints(HP_MAX);
	}

	else if (getEnergy() > 0 && getHitPoints() == HP_MAX)
		std::cout <<  SCAV_PREFIX(CYAN, getName())
				<< FULL_HP << RESET << std::endl;

	else
		std::cout <<  SCAV_PREFIX(YELLOW, getName())
				<< NOEREP << RESET << std::endl;
}
