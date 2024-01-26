#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>     // bu kütüphaneyi renklendirmek için kullandým

#define MAXROW 100
#define MAXCOL 100

char gameBoard[MAXROW][MAXCOL];
int i,j,oyunSayisi=0,puan=0,maxPuan=0,ROW,COL;



char shapes[5][4][4][4] = {   // Þekilleri döndürme iþini fonksiyon ile de yapabilirdim 
		{				      // ama zaten az sayýda þekil olduðu için elimle tanýmlamak daha kolay geldi
		{{'X',' ',' ',' '},
		 {'X',' ',' ',' '},
		 {'X',' ',' ',' '},
		 {'X',' ',' ',' '}},
		 
		{{'X','X','X','X'},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}},
		
		{{'X',' ',' ',' '},
		 {'X',' ',' ',' '},
		 {'X',' ',' ',' '},
		 {'X',' ',' ',' '}},
		 
		{{'X','X','X','X'},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}}},
		 
		
		{
		{{'X',' ',' ',' '},
		 {'X','X',' ',' '},
		 {' ','X',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{' ','X','X',' '},
		 {'X','X',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}},
		
		{{'X',' ',' ',' '},
		 {'X','X',' ',' '},
		 {' ','X',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{' ','X','X',' '},
		 {'X','X',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}}},
		 	 
		
		{
		{{'X',' ',' ',' '},
		 {'X','X',' ',' '},
		 {'X',' ',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{'X','X','X',' '},
		 {' ','X',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}},
		
		{{' ','X',' ',' '},
		 {'X','X',' ',' '},
		 {' ','X',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{' ','X',' ',' '},
		 {'X','X','X',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}}},
		 
		 
		 {
		{{'X','X',' ',' '},
		 {'X','X',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{'X','X',' ',' '},
		 {'X','X',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}},
		
		{{'X','X',' ',' '},
		 {'X','X',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{'X','X',' ',' '},
		 {'X','X',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}}},
		 
		 
		 {
		{{'X',' ',' ',' '},
		 {'X',' ',' ',' '},
		 {'X','X',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{'X','X','X',' '},
		 {'X',' ',' ',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}},
		
		{{'X','X',' ',' '},
		 {' ','X',' ',' '},
		 {' ','X',' ',' '},
		 {' ',' ',' ',' '}},
		 
		{{' ',' ','X',' '},
		 {'X','X','X',' '},
		 {' ',' ',' ',' '},
		 {' ',' ',' ',' '}}}
		     
	};
	
	int satir;
	int sutun;
	HANDLE hConsole;

void random(){                // Random bir þekil ürettiyor.
	satir = rand() % 5;
	sutun = rand() % 4;
	
	// GAMEBOARD
    printf(" ");
    for (j = 0; j < COL; j++) {
        printf("_");
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    printf("		Puan: %d		Rekor: %d",puan,maxPuan);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    printf("\n");

    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("%c", gameBoard[i][j]);
        }
        printf("|\n");
    }

    printf(" ");
    for (j = 0; j < COL; j++) {
        printf("%d",(j+1)%10);
    }
    printf("\n\n");

	for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%c", shapes[satir][sutun][i][j]);
        }
        printf("\n");
    }
}

void rotate(){			// Þekilleri döndürüyor.
	int devamEt = 1;
	while (devamEt) {
        printf("Saga dondurmek icin \"d\", sola dondurmek icin \"a\", dondurmek istemiyorsaniz \"s\" tusuna basin:");
        char islem;
        scanf(" %c", &islem);

        if (islem == 's') {
            devamEt = 0;
        } else if (islem == 'd') {
            sutun++;
            if (sutun > 3) {
                sutun = sutun - 4;
            }
        } else if (islem == 'a') {
            sutun--;
            if (sutun < 0) {
                sutun = sutun + 4;
            }
        }
        system("cls");
        
	    // GAMEBOARD
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("_");
	    }
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    	printf("		Puan: %d		Rekor: %d",puan,maxPuan);
    	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	    printf("\n");
	
	    for (i = 0; i < ROW; i++) {
	        printf("|");
	        for (j = 0; j < COL; j++) {
	            printf("%c", gameBoard[i][j]);
	        }
	        printf("|\n");
	    }
	
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("%d",(j+1)%10);
	    }
	    printf("\n\n");
		
		for (i = 0; i < 4; i++) {
        	for (j = 0; j < 4; j++) {
            	printf("%c", shapes[satir][sutun][i][j]);
        	}
        	printf("\n");
    	}
    	
	}
    
}

void location(){          // Kullanýcýdan x koordinatýný alýyor ve þeklin gidebileceði en aþaðý satýrý belirleyip animasyonlu bir þekilde gönderiyor.
	//Þeklin yatay geniþliðini bulmak istiyorum
	int genislik=0;
	for(j=0;j<4;j++){
		i=0;
		int flag=0;
		while(flag==0 && i<4){
			if(shapes[satir][sutun][i][j] == 'X'){
				flag++;
			}
			i++;
		}
		if(flag==1){
			genislik++;
		}
	}
	
	//Þeklin dikey uzunluðunu bulmak istiyorum
	int uzunluk=0;
	for(i=0;i<4;i++){
		j=0;
		int flag=0;
		while(flag==0 && j<4){
			if(shapes[satir][sutun][i][j] == 'X'){
				flag++;
			}
			j++;
		}
		if(flag==1){
			uzunluk++;
		}
	}
	
	printf("Seklin sol ust kosesini yerlestirmek istediginiz x koordinatini giriniz:");
	int koordinat;
	scanf("%d",&koordinat);
	
	// kullanýcý sutün sayýsýndan daha büyük bir deðer girerse en sona, daha küçük bir deðer girerse en saða yaslayacaðým.
	if(koordinat > COL){
		koordinat = COL;
	}else if(koordinat < 1){
		koordinat = 1;
	}
	
	//þekillerin fazlasýnýn dýþarýya taþmasýný engelledim.
	if(koordinat == (COL-2) && genislik>3){
		koordinat = koordinat - genislik + 3;
	}else if(koordinat== (COL-1) && genislik>2){
		koordinat = koordinat - genislik + 2;
	}else if(koordinat==COL && genislik>1){
		koordinat = koordinat - genislik + 1;
	}
	
	int control=1,a=-1, enAlt=0;
	while(control==1 && enAlt<ROW){
		a++;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(shapes[satir][sutun][i][j] == 'X'  && gameBoard[a+i][koordinat-1+j] == 'X'){
					control=0;
				}
			}			
		}
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(shapes[satir][sutun][i][j] == 'X'){
					gameBoard[a-1+i][koordinat-1+j] = 'X';
				}
			}			
		}
		// GAMEBOARD
		system("cls");
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("_");
	    }
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    	printf("		Puan: %d		Rekor: %d",puan,maxPuan);
    	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	    printf("\n");
	
	    for (i = 0; i < ROW; i++) {
	        printf("|");
	        for (j = 0; j < COL; j++) {
	            printf("%c", gameBoard[i][j]);
	        }
	        printf("|\n");
	    }
	
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("%d",(j+1)%10);
	    }
	    printf("\n\n");
	    usleep(80000);
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(shapes[satir][sutun][i][j] == 'X'){
					gameBoard[a-1+i][koordinat-1+j] = ' ';
				}
			}			
		}
		// GAMEBOARD 2
		system("cls");
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("_");
	    }
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    	printf("		Puan: %d		Rekor: %d",puan,maxPuan);
    	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	    printf("\n");
	
	    for (i = 0; i < ROW; i++) {
	        printf("|");
	        for (j = 0; j < COL; j++) {
	            printf("%c", gameBoard[i][j]);
	        }
	        printf("|\n");
	    }
	
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("%d",(j+1)%10);
	    }
	    printf("\n\n");
		
		
		enAlt=a+uzunluk-1;
	}
	a--;
	
	for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(shapes[satir][sutun][i][j] == 'X'){
					gameBoard[a+i][koordinat-1+j] = 'X';
				}
			}			
		}
		
	puan++;	
	system("cls");

}

deleteRow(){       // Satýrýn tamamý dolduðunda o satýrý siliyor.
	i=ROW-1;
	for(i=ROW-1;i>=0;i--){
		int flag=0,j=0;
		while(flag==0 && j < COL){
			if(gameBoard[i][j] != 'X'){
				flag=1;
			}
			j++;
		}
		
		if(flag == 0){
			
			// GAMEBOARD
			int b,c;
		    printf(" ");
		    for (b = 0; b < COL; b++) {
		        printf("_");
		    }
		    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    		printf("		Puan: %d		Rekor: %d",puan,maxPuan);
    		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		    printf("\n");
		
		    for (c = 0; c < i; c++) {
		        printf("|");
		        for (b = 0; b < COL; b++) {
		            printf("%c", gameBoard[c][b]);
		        }
		        printf("|\n");
		    }
		    printf("|");
		    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		    for(j = 0; j < COL; j++){
				printf("%c", gameBoard[i][j]);
			}
		    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		    printf("|\n");
		    
		    for (c = i+1; c < ROW; c++) {
		        printf("|");
		        for (b = 0; b < COL; b++) {
		            printf("%c", gameBoard[c][b]);
		        }
		        printf("|\n");
		    }
		
		    printf(" ");
		    for (b = 0; b < COL; b++) {
		        printf("%d",(b+1)%10);
		    }
		    printf("\n\n");
			usleep(500000);
			system("cls");
			
			int a;
			for(a=i;a>0;a--){
				for(j=0;j<COL;j++){
					gameBoard[a][j]=gameBoard[a-1][j];
				}
			}
			for(j=0;j<COL;j++){
				gameBoard[0][j]= ' ';
			}
			puan += COL;
			i=ROW;		
		}
	}
}

int isGameOver(){
	int flag=1,j=0;
	while(flag==1 && j<COL){
		if(gameBoard[0][j]=='X'){
			flag=0;
			oyunSayisi++;
			if(puan>maxPuan){
				maxPuan=puan;
			}
		}
		j++;
	}
	system("cls");
	
	// GAMEBOARD
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("_");
	    }
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    	printf("		Puan: %d		Rekor: %d",puan,maxPuan);
    	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	    printf("\n");
	
		printf("|");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		for(j = 0; j < COL; j++){
			printf("%c", gameBoard[0][j]);
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		printf("|\n");
		
	    for (i = 1; i < ROW; i++) {
	        printf("|");
	        for (j = 0; j < COL; j++) {
	            printf("%c", gameBoard[i][j]);
	        }
	        printf("|\n");
	    }
	
	    printf(" ");
	    for (j = 0; j < COL; j++) {
	        printf("%d",(j+1)%10);
	    }
	    
	    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		printf("\n\nGAME OVER\n\n");
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	
	return flag;
}

int menu(){
	if(oyunSayisi==0){
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		printf("1. Oyuna Basla\n");	
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}else{
		printf("Son Oyunun Puani:%d     Rekor:%d\n\n",puan,maxPuan);
		
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		printf("1. Oyuna Tekrar Basla\n");
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);	
		
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	printf("2. Kurallari ogren\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf("3. Oyundan cik\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	
    printf("Seciminizi yapin:");
    int secim;
    scanf(" %d",&secim); 
	if(secim==1){
		puan=0;
		system("cls");
		printf("\nSatir sayisini giriniz:\n");
	    	scanf("%d",&ROW);
	    	printf("Sutun sayisini giriniz:\n");
	    	scanf("%d",&COL);
	    	
	    	for(i=2;i>=0;i--){
	    		system("cls");
	    		printf("\n%d\n",i+1);
	    		printf("Oyun basliyoor...");
	    		sleep(1);
			}
	    	
		for(i=0; i < ROW; i++){
			for(j=0; j < COL; j++){
				gameBoard[i][j] = ' ';
			}
		} 
	    while(isGameOver()){
	    	system("cls");
	    	random();
	    	rotate();
	    	location();
	    	deleteRow();	    	
		}
		for(i=0; i < ROW; i++){
		for(j=0; j < COL; j++){
			gameBoard[i][j] = ' ';
		}
	} 
	}else if(secim==3){
		return 0;
	}else if(secim==2){
		system("cls");
		system("cls");
    	printf("Tetris Oyunu Kurallari:\n\n");

    	printf("1. Oyunun Amaci:\n");
    	printf("   - Oyunun amaci, dusen bloklari yatay bir sekilde bir araya getirerek tam dolu satirlar olusturmaktir.\n");
    	printf("   - Dolu satirlar silinerek oyuncu puan kazanir ve yeni bloklar duser.\n\n");

	    printf("2. Kontroller:\n");
	    printf("   - Bloklari dondurmek icin 'a' (sola), 'd' (saga) tuslarini kullanabilirsiniz.\n");
	    printf("   - Bloklari istediginiz konuma yerlestirmek icin x koordinatini girmeniz gerekmektedir.\n\n");
	
	    printf("3. Blok Turleri:\n");
	    printf("   - Oyunda bes farkli blok turu vardir ve her biri farkli sekilde dondurulebilir.\n\n");
	
	    printf("4. Puanlama:\n");
	    printf("   - Dolu satirlar silindiginde, satirin uzunlugu kadar puan kazanilir.\n");
	    printf("   - Her bir sekil yerlestiginde 1 puan kazanilir.\n\n");
	
	    printf("Menuye donmek icin herhangi bir tusa basiniz.\n");
		char kural;
		scanf(" %c",&kural);
		system("cls");
	}
	return 1;
}


int main () {
	srand(time(0));   // random için gerekli
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   // renklendirme için gerekli
	
	int cikis  = 1;
	while(cikis != 0) {
		cikis =	menu();
	}
	
	return 0;
}
