#include "all_DSP.h"<?xml version="1.0" encoding="ISO-8859-1"?>
 /*! Here is a snapshot of my new application:
   *  \image html all_DSP.png
   *  \image latex application.eps "My application" width=10cm
 */


<?xml version="1.0" encoding="ISO-8859-1"?> conv ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	     
    float32_t  [var]  ;
    float32_t  [var]  ;
    float32_t  [ ( var + var )  - 1 ] ;
	
    arm_conv_f32(  ,
    &var,
     ,
    &var,
     );
	
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>
}<?xml version="1.0" encoding="ISO-8859-1"?> co-relate ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	     
    float32_t  [var]  ;
    float32_t  [var]  ;
    float32_t  [ (2 * (var) ) -1 ] ;
	
    arm_correlate_f32(  ,
    &var,
     ,
    &var,
     );
	
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>
}<?xml version="1.0" encoding="ISO-8859-1"?> vector_sub ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	     
   float32_t  [var]  ;
   float32_t  [var]  ;
   float32_t  [var] ;
	
	arm_sub_f32(  ,, , &var  );
	<?xml version="1.0" encoding="ISO-8859-1"?>
}<?xml version="1.0" encoding="ISO-8859-1"?> vect_neg ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	     
   float32_t  [var]  ;
   float32_t  [var] ;
	
	arm_negate_f32(   , , &var   );
	<?xml version="1.0" encoding="ISO-8859-1"?>
}<?xml version="1.0" encoding="ISO-8859-1"?> vect_shift ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?> = var[n]  &lt;&lt; var ;
		
	<?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?><?xml version="1.0" encoding="ISO-8859-1"?>var = vector_shift_result_246;
		
}<?xml version="1.0" encoding="ISO-8859-1"?> vect_add ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	     
   float32_t  [var]  ;
   float32_t  [var]  ;
   float32_t  [var] ;
	
	arm_add_f32(  , ,  , &var  );
	<?xml version="1.0" encoding="ISO-8859-1"?>
}<?xml version="1.0" encoding="ISO-8859-1"?> dot_product ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	     
   float32_t  [var]  ;
   float32_t  [var]  ;
   float32_t  [var] ;
	
	arm_dot_prod_f32(  , , &var  ,  );
	<?xml version="1.0" encoding="ISO-8859-1"?>
}<?xml version="1.0" encoding="ISO-8859-1"?> vect_mu ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
	     
   float32_t  [var]  ;
   float32_t  [var]  ;
   float32_t  [var] ;
	
	arm_mult_f32(  , ,  ,&var   );
	<?xml version="1.0" encoding="ISO-8859-1"?>
}