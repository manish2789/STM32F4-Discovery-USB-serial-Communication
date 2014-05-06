#include "GATES.h"<?xml version="1.0" encoding="ISO-8859-1"?>
 /*! Here is a snapshot of my new application:
   *  \image html GATES.png
   *  \image latex application.eps "My application" width=10cm
 */


<?xml version="1.0" encoding="ISO-8859-1"?> AND ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
		uint32_t  = a&&b  ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = AND_logic;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> OR ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
	uint32_t  = a || b ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = OR;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> equal to ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
   uint32_t    = (a == b)  ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = eq;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> NOR ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
	uint32_t  = ~ (a | b) ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = NOR;
		
}