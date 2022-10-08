#include <stdio.h>
            
    struct employeeData {                              
    unsigned int idNum; 
    char lastName[ 15 ];    
    char firstName[ 10 ];   
    double balance;   
    };                  
 
    int main( void )  { 
    FILE *cfPtr; 

    struct employeeData employee = { 0, "", "", 0.0 };

    if ( ( cfPtr = fopen( "a.txt", "rb+" ) ) == NULL ) {
      puts( "File could not be opened." );
    }
    else { 

      printf( "%s", "Enter account number"
         " ( 1 to 100, 0 to end input )\n? " );
		 scanf( "%d", &employee.idNum );

    while ( employee.idNum != 0 ) { 
 
    printf( "%s", "Enter lastname, firstname, balance\n? " );

    fscanf( stdin, "%14s%9s%lf",employee.lastName, 
              employee.firstName, &employee.balance );
  
      fseek( cfPtr, ( employee.idNum - 1 ) *              
            sizeof( struct employeeData ), SEEK_SET );         
           
      fwrite( &employee, sizeof( struct employeeData ), 1, cfPtr );

      printf( "%s", "Enter account number\n? " );
      scanf( "%d", &employee.idNum );
      } 
      fclose( cfPtr ); 
      }
    }
