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
#define NOTCOOL		"can't request a high five cause isdead"


#define SCAV_PREFIX(color, name)	color << "FragTrap \"" << name << "\" "
#define STATUS(hp, energy)			"[ hp:" << hp << " ep:" << energy << " ] "

/* ===================== Orthodox Canonical Form ====================== */


FragTrap::FragTrap( void ) : 
	ClapTrap() {
	_hitPoints = HP_MAX;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << SCAV_PREFIX(WHITE, _name) << READY << RESET << std::endl;
}


FragTrap::FragTrap( std::string name ) : 
	ClapTrap( name ) {
	_hitPoints = HP_MAX;
	_energyPoints = 100;
	_attackDamage = 30;
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
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return ( *this );
}


/* =========================== needed functions ============================ */


void	FragTrap::highFivesGuys( void ) {

	std::cout << STATUS(getHitPoints(), getEnergy());

	if (_hitPoints == 0)
		std::cout << SCAV_PREFIX(YELLOW, _name) << NOTCOOL << RESET << std::endl;
	else
		std::cout << SCAV_PREFIX(CYAN, _name) << COOL << RESET << std::endl;
}

