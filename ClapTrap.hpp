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
/*   ClapTrap.hpp                                            ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
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

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

# define RED	"\033[1;91m"
# define GREEN	"\033[1;92m"
# define YELLOW	"\033[1;93m"
# define PURPLE	"\033[1;95m"
# define CYAN	"\033[1;96m"
# define RESET	"\033[0m"

# ifndef DEBUG
#  define DEBUG false
# endif

class ClapTrap {

public:

	ClapTrap ( void );
	ClapTrap ( std::string name );
	ClapTrap ( ClapTrap const & cp );
	~ClapTrap ( void );

	ClapTrap & operator=( ClapTrap const & src );

	void    attack(const std::string& target);
	void    takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

} ;

#endif