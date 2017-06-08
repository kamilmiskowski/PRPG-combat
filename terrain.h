
//Creates map wich will be printed on the screen

 char T[20][40];
 
 void fillT() 
 {
 	for(int i=0;i<5;i++)
		{
 	   		for(int j=0;j<40;j++) T[i][j]=178;
	 	 }
	  
 	 for(int i=5;i<16;i++)
 		  {
 	   		for(int j=0;j<40;j++) T[i][j]=219;
		 }
	 
 	 for(int i=16;i<20;i++)
 	 	 {
 	   	   	for(int j=0;j<40;j++) T[i][j]=178;
	 	  }
	   	
 }
 
 