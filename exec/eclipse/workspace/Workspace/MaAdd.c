#include "MaAdd.h"<?xml version="1.0" encoding="ISO-8859-1"?>
 /*! Here is a snapshot of my new application:
   *  \image html MaAdd.png
   *  \image latex application.eps "My application" width=10cm
 */


<?xml version="1.0" encoding="ISO-8859-1"?> mat_ADD ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	 arm_status status; 
     
    arm_matrix_instance_f32    ;
    arm_matrix_instance_f32    ;
	arm_matrix_instance_f32    ;
	
	  const float32_t  _data[4];
	  const float32_t  _data[4];
      const float32_t  _data[4];
      
      arm_mat_init_f32( & , 
      var1  , 
      var2,
      _data );
 
      arm_mat_init_f32( & , 
      var3  , 
      var4,
      _data );
		
	  arm_mat_init_f32( & ,
	  var5 ,
	  var6 ,
	  _data );
		  
	  status = arm_mat_add_f32( & ,
      & ,  & );		
 
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>
}