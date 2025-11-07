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
/*   main.cpp                                                ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
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

#include "DiamondTrap.hpp"


int main( void ) {

	DiamondTrap a;
	DiamondTrap b("Romie");
	DiamondTrap c(b);
	ScavTrap	d;
	FragTrap	e;

	std::cout << "\n" << WHITE;

	a.whoami();
	b.whoami();
	c.whoami();

	std::cout << "\n";

	std::cout << GREEN << "DiamondTrap's defaults hp is : " << c.getHitPoints()
					<< "\nDiamondTrap's defaults ep is : " << c.getEnergy() 
					<< "\nDiamondTrap's defaults ap is : " << c.getAttack() << "\n" << RESET << std::endl;


	std::cout << GREEN << "ScavTrap's defaults hp is : " << d.getHitPoints()
					<< "\nScavTrap's defaults ep is : " << d.getEnergy() 
					<< "\nScavTrap's defaults ap is : " << d.getAttack() << RESET << "\n" << std::endl;

	
	std::cout << GREEN << "FragTrap's defaults hp is : " << e.getHitPoints()
					<< "\nFragTrap's defaults ep is : " << e.getEnergy() 
					<< "\nFragTrap's defaults ap is : " << e.getAttack() << RESET << std::endl;

	std::cout << "\n";

	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	std::cout << "\n";

}