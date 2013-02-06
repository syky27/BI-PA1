#include <stdio.h>
#include <stdlib.h>
#define DAY 1440
#define HOMELESS 180
#ifndef TRUE
#define TRUE 1
#endif 
#ifndef FALSE
#define FALSE 0
#endif 
#define TIME_MIN  5
#define TIME_MAX  180

	int TransferAble(int AP, int BP, int BO)
	{


	int iRet = FALSE;
	if	(((BO > AP) && ((BO - AP) >= TIME_MIN) && (abs(AP - BO) <= TIME_MAX)) || ((BO > AP) && ((BO - AP) >= TIME_MIN) && (abs(BP - AP) <= TIME_MAX)) || (((BP-AP)<TIME_MAX) && ((AP+1440-BP)<=TIME_MAX) &&(AP+1440-BP)>0))
		{ 
			iRet = TRUE;
		}
		else if((BO + 1440 - AP) >= TIME_MIN) 
		{
		if ((BO<BP)&&(AP < BO) && ((BP - (AP +1440)) <= TIME_MAX)) iRet = TRUE; 
		if ((AP < BP) && ((BP - AP) <= TIME_MAX)) iRet = TRUE; 
		else if (((BP + 1440) - AP) <= TIME_MAX) iRet = TRUE; 
		} 
		
		
		

return iRet;

		
	}

	void Equation(char Train01,char Train02,char Train03, int XP, int YP, int ZP, int YO, int ZO)
  {
    
	  
	  if(TransferAble(XP,YP,YO))
	  {
		  
		  if(TransferAble(XP,ZP,ZO))
		  {
			  printf("Z vlaku %c lze prestoupit na vlaky %c a %c.\n",Train01,Train02,Train03);
			 

		  }
		  else
		  {
			  printf("Z vlaku %c lze prestoupit na vlak %c.\n",Train01, Train02);
			  
		  }
	  }
	  else if(TransferAble(XP,ZP,ZO))
	  {
		  printf("Z vlaku %c lze prestoupit na vlak %c.\n",Train01, Train03);
		  
	  }
	  else
	  { 
		  printf("Z vlaku %c nelze prestupovat.\n",Train01);
		 
	  }
	 
  }


	void TimeInput(char Train, int IN, int * hour, int * min)
   {
	   printf("Zadejte cas ");
	   if (IN){
		   printf("odjezdu vlaku %c:\n",Train);
	   }
	   else {printf("prijezdu vlaku %c:\n",Train);
	   }
	   if (scanf("%d:%d",hour, min) !=2 || *hour >= 24 ||*hour < 0 ||*min >= 60 || *min <0){
		   printf("Nespravny vstup.\n");
		   exit(1);
	   }
   }

	

	






	int main(void)
   {
    int APH,APM,AOH,AOM,BPH,BPM,BOH,BOM,CPH,CPM,COH,COM,APMDD,AOMDD,CPMDD,COMDD,BPMDD,BOMDD;
		
	
	
		TimeInput('A', 0, &APH, &APM);
		TimeInput('A', 1, &AOH, &AOM);
		TimeInput('B', 0, &BPH, &BPM);
		TimeInput('B', 1, &BOH, &BOM);
		TimeInput('C', 0, &CPH, &CPM);
		TimeInput('C', 1, &COH, &COM);
				
		APM += APH * 60;
		AOM += AOH * 60;
		BPM += BPH * 60;
		BOM += BOH * 60;
		CPM += CPH * 60;
		COM += COH * 60;
		

		APMDD = APM + DAY;
		AOMDD = AOM + DAY;
		BPMDD = BPM + DAY;
		BOMDD = BOM + DAY;
		CPMDD = CPM + DAY;
		COMDD = COM + DAY;

	
		Equation ('A','B','C',APM,BPM,CPM,BOM,COM);
		Equation ('B','A','C',BPM,APM,CPM,AOM,COM);
		Equation ('C','A','B',CPM,APM,BPM,AOM,BOM);
		
		
		return 0;
	}


