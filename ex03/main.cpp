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
	
	std::cout << "\n" << WHITE;

	a.whoami();
	b.whoami();
	c.whoami();

	std::cout << "\n";

	std::cout << GREEN << "DiamondTrap's defauls hp is : " << c.getHitPoints()
					<< "\nDiamondTrap's defauls ep is : " << c.getEnergy() 
					<< "\nDiamondTrap's defauls ap is : " << c.getAttack() << RESET << std::endl;

	std::cout << "\n";

	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	std::cout << "\n";

}