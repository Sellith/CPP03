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

# define RED	"\e[1;91m"
# define GREEN	"\e[1;92m"
# define YELLOW	"\e[1;93m"
# define PURPLE	"\e[1;95m"
# define CYAN	"\e[1;96m"
# define WHITE	"\e[1;97m"
# define RESET	"\e[0m"

# define HP_MAX	100

# ifndef DEBUG
#  define DEBUG false
# endif

class ClapTrap {

public:

	/* =============== Constructor ============== */

	ClapTrap	( void );
	ClapTrap	( std::string name );
	ClapTrap	( ClapTrap const & cp );

	/* ================ Destrutor =============== */

	~ClapTrap	( void );

	/* ================= Operator =============== */

	ClapTrap & operator= ( ClapTrap const & src );

	/* ================= ClapTrap =============== */

	void    			attack ( const std::string & target );
	void    			takeDamage ( unsigned int amount );
	void				beRepaired ( unsigned int amount );

	/* ================== Getter ================ */

	unsigned int		getHitPoints ( void );
	unsigned int		getEnergy ( void );
	unsigned int		getAttack ( void );
	std::string			getName ( void );


	/* ================== Getter ================ */

	void				setHitPoints ( unsigned int newHp );
	void				setEnergy ( unsigned int newEp );
	void				setAttack ( unsigned int newAp );
	void				setName ( std::string newName );


protected:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

} ;

#endif