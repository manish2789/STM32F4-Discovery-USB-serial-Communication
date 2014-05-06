#include "Logic_fuctions.h"<?xml version="1.0" encoding="ISO-8859-1"?>
 /*! Here is a snapshot of my new application:
   *  \image html Logic_fuctions.png
   *  \image latex application.eps "My application" width=10cm
 */


<?xml version="1.0" encoding="ISO-8859-1"?> Nand_logic ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
	uint32_t  = ~ (a&&) ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = NAND;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> greater_logic ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
    double     = (b>a)  ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = gt;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> less_logic ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
    uint32_t    = (a<b)  ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = lt;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> NOT_logic ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
		uint32_t  = ~ (a) ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>not_a = NOT;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> Xor_logic ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
	uint32_t  = a ^ b ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = XOR;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> greater_tahn_logic ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	
    double    = (a>= b)  ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>out = gteq;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> less_than_equal_to_logic ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>   = (var< = var)  ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>
}