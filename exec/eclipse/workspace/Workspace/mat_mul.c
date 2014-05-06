#include "mat_mul.h"<?xml version="1.0" encoding="ISO-8859-1"?>
 /*! Here is a snapshot of my new application:
   *  \image html mat_mul.png
   *  \image latex application.eps "My application" width=10cm
 */


<?xml version="1.0" encoding="ISO-8859-1"?> Matrix_mul ( ) {
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
      ,
      _data );
		
	  arm_mat_init_f32( & ,
	  var4 ,
	  var6 ,
	  _data );
		  
	  status = arm_mat_mult_f32( & ,
       & ,  & );		
 
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>
}