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

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	{
		ClapTrap dummy("dum");
		ScavTrap a;
		ScavTrap b("HAAH");
		
		std::cout << "\n" << WHITE;
		a.attack(b.getName());
		b.takeDamage(a.getAttack());
		a.attack(dummy.getName());
		dummy.takeDamage(a.getAttack());
		b.guardGate();
		b.guardGate();
		a.attack(b.getName());
		b.takeDamage(a.getAttack());
		b.takeDamage(a.getAttack());
		b.takeDamage(a.getAttack());
		b.attack(a.getName());
		a.beRepaired(a.getAttack());
		b.attack(a.getName());
		a.takeDamage(b.getAttack());
		a.attack(b.getName());
		b.takeDamage(a.getAttack());
		b.takeDamage(a.getAttack());
		b.attack(a.getName());
		b.guardGate();

		std::cout << "\n";
	}
	std::cout << "\n";
	{
		ScavTrap	Marcius("Marcius");
		ScavTrap	lucius("lucius");
		ScavTrap	lucius2(lucius);

		std::cout << "\n";
		Marcius.beRepaired(Marcius.getAttack());
		while (lucius.getHitPoints() >	0 && Marcius.getEnergy() > 0) {
			Marcius.attack(lucius.getName());
			Marcius.attack(lucius.getName());
			lucius.takeDamage(Marcius.getAttack());
			lucius.takeDamage(Marcius.getAttack());
			lucius2.attack(Marcius.getName());
			lucius.beRepaired(lucius.getAttack());
		}
		Marcius.attack(lucius2.getName());
		std::cout << "\n";
	}
}