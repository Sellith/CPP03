/* *************************************************************************************************************** */
/*   DiamondTrap.cpp                                                                                                  */
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

#include "DiamondTrap.hpp"


#define READY		"is ready to kick asses"
#define CLONED		"has been cloned and is ready to kick asses"
#define FINISH		"has successfully KOed the target"

#define DT_PREFIX(color, name)		color << "DiamondTrap \"" << name << "\" "


DiamondTrap::DiamondTrap( void ): ClapTrap( "Random_clap_name" ) {
	_name = "Random";
	_hitPoints = HP_MAX;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << DT_PREFIX(WHITE, _name) << READY << RESET << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap( name + "_clap_name" ) {
	_name = name;
	_hitPoints = HP_MAX;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "\e[1;97mCustom " << DT_PREFIX(WHITE, _name) << READY << RESET << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ): ClapTrap( src ), ScavTrap( src ), FragTrap( src ) {
	_name = src._name;
	std::cout << DT_PREFIX(WHITE, _name) << CLONED << RESET << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << DT_PREFIX(WHITE, _name) << FINISH << RESET << std::endl;
}


void	DiamondTrap::attack( const std::string & target ) {
	ScavTrap::attack( target );
}


void	DiamondTrap::whoami( void ) {

	std::cout << CYAN << "my Diamond name is " << _name << " and my ClapTrap name is " 
		<< ClapTrap::_name << RESET << std::endl;
}