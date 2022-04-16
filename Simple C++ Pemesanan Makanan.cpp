#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

float total;
int stroti;
int stdaging;
int sttomat;
int stsayur;
int stkeju;
int sroti;
int sdaging;
int stomat;
int ssayur;
int skeju;

struct node{
	int jumlah;
	int no_antri;
	float roti;
	float daging;
	float tomat;
	float sayur;
	float keju;
	float bayar;
	struct node *next;
};
typedef struct node node;

//================================================

struct queue{
	int count;
	int antri;
	node *front;
	node *rear;
};
typedef struct queue queue;

//===============================================

queue createQueue(void);
int enqueue(queue *myQueue);
node *creatNode(void);
void dequeue(queue *myQueue);
void destroy(queue *myQueue);
void display(queue myQueue);

//===============================================

int main()
{
	int choice, num, success;
	queue myQueue;
	myQueue=createQueue();
	while(1){
	system("cls");
	printf("|----------B-Cheese Automatic Canteen----------|\n");
	printf("Menu Pelanggan\n");
	printf("1. Pesan Makanan\n");
	printf("2. Pesanan Diterima\n");
	printf("3. Daftar Antrian\n\n");
	printf("Menu Penjual\n");
	printf("4. Isi Stock\n");
	printf("5. Cek Stock\n");
	printf("6. Total Uang Diterima\n");
	printf("7. Exit\n");
	printf("Masukkan Pilihan: ");
	fflush(stdin);
	scanf("%d",&choice);
	printf("\n\n");
	switch(choice){
	  	case 1:
	  		system("cls");
	  		if(stroti > 3){
				if (stsayur > 3){
					if (sttomat > 3){
						if (stdaging > 3){
							if (stkeju > 3){
						        success = enqueue(&myQueue);
						        if(success==0){
						        	printf("\n");
					        		printf("Jumlah Antrian Maksimal. Harap isi pesanan lagi setelah antrian berkurang. Terima kasih :)");
								}
							}else{printf("Stock keju kurang! Tunggu stock ditambahkan!");}
						}else{printf("Stock daging kurang! Tunggu stock ditambahkan!");}
					}else{printf("Stock tomat kurang! Tunggu stock ditambahkan!");}
				}else{printf("Stock sayur kurang! Tunggu stock ditambahkan!");}
	        }else{printf("Stock roti kurang! Tunggu stock ditambahkan!");}
			getch();
		break;
		case 2:
			dequeue(&myQueue);
			getch();
		break;
		case 3:
			display(myQueue);
			getch();
		break;
		case 4:
			system("cls");
			printf("Tambah Stock\n");
	        printf("Roti\t: ");
	        fflush(stdin);
			scanf("%d", &sroti);
			printf("Sayur\t: ");
	        fflush(stdin);
			scanf("%d", &ssayur);
			printf("Tomat\t: ");
	        fflush(stdin);
			scanf("%d", &stomat);
			printf("Daging\t: ");
	        fflush(stdin);
			scanf("%d", &sdaging);
			printf("Keju\t: ");
	        fflush(stdin);
			scanf("%d", &skeju);
			printf("Stock telah ditambahkan!");
			
			stroti = stroti + sroti;
			stsayur = stsayur + ssayur;
			sttomat = sttomat + stomat;
			stdaging = stdaging + sdaging;
			stkeju = stkeju + skeju;
			
			getch();
	    break;
	    case 5:
	    	system("cls");	    	
	    	printf("Stock bahan\n");
	    	printf("Stock roti\t= %d\n",stroti);
	    	printf("Stock sayur\t= %d\n",stsayur);
	    	printf("Stock tomat\t= %d\n",sttomat);
	    	printf("Stock daging\t= %d\n",stdaging);
	    	printf("Stock keju\t= %d\n",stkeju);
	    	getch();
	    break;
		case 6:
			system("cls");
			printf("Total Uang Diterima = $ %.2f\n",total);
			getch();
		break;
		case 7:
			destroy(&myQueue);
			exit(1);
		default:printf("\nPilihan salah\n");
		break;
	  }
	}
	
	return 0;
}

//====================================================

queue createQueue(void)
{
	queue myQueue;
	myQueue.count=0;
	myQueue.antri=0;
	myQueue.front=NULL;
	myQueue.rear=NULL;
	return(myQueue);
}

//====================================================

int enqueue(queue *myQueue)
{
	int roti;
	int daging;
	int tomat;
	int sayur;
	int keju;
	int nomor;
	int no_antri;
	int success;
	float bayar;
	
	system("cls");
	printf("Pilih isian sandwich\n");

	printf("Pakai roti?\n");
	printf("1. Ya\n");
	printf("2. Extra\n");
	printf("0. Tidak\n");
	printf("Pilihan\t\t: ");
	fflush(stdin);
	scanf("%d",&roti);

	printf("Pakai sayur?\n");
	printf("1. Ya\n");
	printf("2. Extra\n");
	printf("0. Tidak\n");
	printf("Pilihan\t\t: ");
	fflush(stdin);
	scanf("%d",&sayur);
	
	printf("Pakai tomat?\n");
	printf("1. Ya\n");
	printf("2. Extra\n");
	printf("0. Tidak\n");
	printf("Pilihan\t\t: ");
	fflush(stdin);
    scanf("%d",&tomat);
    
    printf("Pakai daging?\n");
	printf("1. Ya\n");
	printf("2. Extra\n");
	printf("0. Tidak\n");
	printf("Pilihan\t\t: ");
	fflush(stdin);
	scanf("%d",&daging);
	
	printf("Pakai keju?\n");
	printf("1. Ya\n");
	printf("2. Extra\n");
	printf("0. Tidak\n");
	printf("Pilihan\t\t: ");
	fflush(stdin);
	scanf("%d",&keju);
    
    bayar = roti + (sayur * 0.25) + (tomat * 0.5) + (daging * 3) + keju;
    system("cls");
    printf("Total yang harus Anda bayar: $ %.2f \n\n", bayar);
    fflush(stdin);
	nomor = myQueue->antri;
	nomor++;
	no_antri = nomor;
    
	if(myQueue->count>=3) success=0;
	else
	{
		node *newPtr;
		newPtr=(node*)malloc(sizeof(node));
		newPtr->no_antri=no_antri;
		newPtr->roti=roti;
		newPtr->sayur=sayur;
		newPtr->tomat=tomat;
		newPtr->daging=daging;
		newPtr->keju=keju;
		newPtr->bayar=bayar;
		
		newPtr->next=NULL;
		if(myQueue->front==NULL)
		{
			myQueue->front=newPtr;
		}
		else
		{
		   myQueue->rear->next=newPtr;
		}
		myQueue->rear=newPtr;
		myQueue->count++;
		myQueue->antri++;
		success=1;
	}
	printf("Harap menunggu pesanan Anda. Terima kasih :)\n");
	return success;
}

//===============================================

node *createNode(void)
{
	node *newPtr;
	
	newPtr=(node *)malloc(sizeof(newPtr));
	return(newPtr);
}

//================================================

void dequeue(queue *myQueue)
{
	float dequeue;
	int dequeueroti;
	int dequeuesayur;
	int dequeuetomat;
	int dequeuedaging;
	int dequeuekeju;
	
	system("cls");
	if(myQueue->count==0) {
	printf("Antrian kosong!");
	}
	else
	{
		printf("Data Antrian\n");
		node *dltPtr,*newPtr;
		dltPtr = myQueue -> front;
		dequeueroti = dltPtr -> roti;
		dequeuesayur = dltPtr -> sayur;
		dequeuetomat = dltPtr -> tomat;
		dequeuedaging = dltPtr -> daging;
		dequeuekeju = dltPtr -> keju;
		dequeue = dltPtr -> bayar;
		printf("Nomor Antri\t= %d\nBayar\t\t= $ %.2f\n\n", dltPtr->no_antri, dequeue);
		total = total + dequeue;
		stroti = stroti - dequeueroti;
		stsayur = stsayur - dequeuesayur;
		sttomat = sttomat - dequeuetomat;
		stdaging = stdaging - dequeuedaging;
		stkeju = stkeju - dequeuekeju;
		printf("Pembayaran Selesai. Terima kasih :)");
		myQueue->front = myQueue->front->next;
		free(dltPtr);
		myQueue->count--;
	}
}

//==============================================

void destroy(queue *myQueue)
{
	node *temp;
	
	while(myQueue->count!=0)
	{
		temp=myQueue->front;
		myQueue->front=myQueue->front->next;
		myQueue->count--;
		free(temp);
	}
	
	myQueue->count=0;
	myQueue->front=NULL;
	myQueue->rear=NULL;
}

//=============================================

void display(queue myQueue)
{
	node *temp;
	
	system("cls");
	temp=myQueue.front;
	printf("Daftar Antrian\n");
	while(temp)
	{
		printf("\nNomor Antrian\t= %d\nTotal Biaya\t= $ %.2f\n\n",temp->no_antri, temp->bayar);
		temp=temp->next;
	}
}

//=============================================	

