#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include<time.h>
#include <unistd.h>
#define NT 200 //nbre maximal de targets
#define NC 500 //nbre maximal de capteurs
#define SR 100 // maximum senssing range
#define B 50 /*budget fixe*/
typedef struct Capteur
{
    int id; // Identifiant du capteur
    double rayon;//Le rayon du capteur
    double duree;//La duree du capteur
    double distance[NT];//c'est un tableau qui contient les differentes distances qu sépare un capteur donnee
    double prix;//Le prix du capteur
    char typeSurveillance;//type de surveillance du capteur

} Capteur;
void jeuxInstance(int N,int M,int Emax,int Emin,int prix,float P[],int area,int range,float E[] ,float RS[],float XS[],float YS[],float XT[],float YT[],double Distance[NC][NT],char *S)
{FILE* fichier = NULL;
fichier = fopen(S, "w");
char c;
char line[10000];
int delta[NC][NT];
int K1=N/4;//K-Coverage:par exemple: chaque cible est au moins couvert par 1 capteurs
int K2=0;// chaque capteurs couvre au moins k2 cibles
int s=0;
int ok1=0,ok2=0;
if (fichier != NULL)
{//srand(time(NULL));
    printf("*********************************entref1\n*************************");
    /* printf ("Rentrez la zone a couvrir area = ");
     scanf ("%d", &area);
     printf ("Rentrer le nombre de capteurs N =");
     scanf ("%d", &N);*/
     fputs("Nombre des capteurs:\n", fichier);
     sprintf (line, "%d", N);
     printf("*********************************entref2\n*************************");
     //printf("line %s", line);
     // c=(char)N+'0';
     fputs(line,fichier);
     fputs("\n",fichier);
     // printf("%c\n",c);
    /* printf ("Energie maximale d'un capteur =");
     scanf ("%d", &Emax);
     printf ("le prix maximal maximale d'un capteur =");
     scanf ("%f", &prix);
     printf ("Rentrer le nombre de targets M =");
     scanf ("%d", &M);*/
     //c=(char)M+ '0';
    fputs("Nombre des targets:\n", fichier);
    sprintf (line, "%d", M);
    printf("*********************************entref3\n*************************");
    fputs(line,fichier);
    fputs("\n",fichier);
    fputs("Nombre de type de surveillance:\n",fichier);
    fputs("1\n",fichier);
    fputs("\n",fichier);
    fputs("Caracteristiques:\n",fichier);
   // printf ("area");
    // scanf ("%d", &range);*
     printf("\n");
     //printf("*****************n %d********************",area);
       for(int i=0; i < N;i++)
   {
       XS[i]=HAS_Float(area);
       YS[i]=HAS_Float(area);
   }

   printf( "XS= ");
      for(int i=0; i < N;i++)
    {
       printf( "%f |  ",XS[i]);
    }
    printf("\n");
    printf( "YS= ");
      for(int i=0; i < N;i++)
    {
       printf( "%f |  ",YS[i]);
    }
     for(int i=0; i < N;i++)
   {
       RS[i]=HAS_Float(range)+100;
   }
   printf("\n");
   printf( "RS= ");
     for(int i=0; i < N;i++)
    {
       printf( "%f |  ",RS[i]);
    }
    printf("\n");

     printf( "E= ");
     for(int i=0; i < N;i++)
   {
       E[i]=HAS_Float(Emax-Emin)+Emin;

   }
    for(int i=0; i < N;i++)
    {
       printf( "%f |  ",E[i]);
    }
    printf("\n");
        printf("\n");
     printf( "P= ");
     for(int i=0; i < N;i++)
   {
       P[i]=HAS_Float(prix)+1;
   }
    for(int i=0; i < N;i++)
    {
       printf( "%f |  ",P[i]);
    }
    printf("\n");
while (ok2==0)
{
for(int h=0; h < M;h++)
   {ok1=0;
       while(ok1==0)
       {

       XT[h]=HAS_Float(area);
       YT[h]=HAS_Float(area);

    for(int i=0;i<N;i++)
    {

        Distance[i][h]=sqrt(((XS[i]-XT[h])*(XS[i]-XT[h]))+((YS[i]-YT[h])*(YS[i]-YT[h])));
      //  printf( "%lf |  ",Distance[i][j]);

       // printf("\n");
    }
    /**********************************/
     for(int i=0;i<N;i++)
    {

            if(Distance[i][h]<=RS[i])
            {
                delta[i][h]=1;
            }
            else
            {
                delta[i][h]=0;
            }

        }

    printf("\n");
      s=0;
        for(int i=0;i<N;i++)
        {
            if (delta[i][h]==1) {s=s+1;}
        }

        if(s>=K1) {ok1=1;}
    }
   }
    for(int i=0;i<N;i++)
    {   s=0;
        for(int j=0;j<M;j++)
        {
            if (delta[i][j]==1) {s=s+1;

                                 }
        }

        if(s>=K2)  {ok2=1;}
        else {
                i=N;
        ok2=0;}
    }
}

    /****************************************/

     printf("\n");
  for(int i=0;i<N;i++)
     {
         for(int j=0;j<M;j++)
    {
        printf("%d",delta[i][j]);
    }
    printf("\n");
     }
      printf( "XT=");
   for(int i=0; i < M;i++)
    {
       printf( "%f |  ",XT[i]);
    }
    printf("\n");
    printf( "YT=  ");
      for(int i=0; i < M;i++)
    {
       printf( "%f |  ",YT[i]);
    }
    printf("\n");
    printf("\n");
    printf("Distance= \n");
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
        printf( "%lf |  ",Distance[i][j]);
        }
        printf("\n");
    }

  for(int i=0;i<N;i++)
    {
        sprintf(line,"%f", RS[i]);
        fputs(line,fichier);
        fputs(" ",fichier);
        sprintf (line,"%f", E[i]);
        fputs(line,fichier);
        fputs(" ",fichier);
        sprintf (line,"%f", P[i]);
        fputs(line,fichier);
        fputs(" ",fichier);
        fputs("a ",fichier);
        for(int j=0;j<M;j++)
        {
           sprintf (line,"%lf", Distance[i][j]);
           fputs(line,fichier);
           fputs(" ",fichier);
        }
        fputs("\n",fichier);
    }
    fputs("Type de surveillance de chaque endroit(target):tab[nombre de target]\n",fichier);
    for (int i=0;i<M;i++)
    {
        fputs("a ",fichier);
    }

}
fclose(fichier);
}

void lire_Data(Capteur Cap[],int *N,int *M,char *S ,char *survTarget,int *nbreDeTypeDeSur)
{
    // Role:
    //cette fonction permet de lire toutes  les donnees necessaires pour la simulation a partir d'un fichier S

   int i,j,k,L,C;
   FILE *file = NULL; // fichier pour lire les données


   file =fopen ( S, "r" );
   if ( file != NULL )
   {//printf("entrer");
      char line [ 100028 ]; /* or other suitable maximum line size */
      char S[100000];
      fgets ( line, sizeof line, file );  /* read a line */
      fgets ( line, sizeof line, file );
      *N = atoi(line);
     // printf("***************N=%d\n",*N);
       fgets ( line, sizeof line, file );
       fgets ( line, sizeof line, file );
       *M = atoi(line);
      // printf("***************M=%d\n",*M);
        fgets ( line, sizeof line, file );
       fgets ( line, sizeof line, file );
       *nbreDeTypeDeSur = atoi(line);
       //printf("***************=%d\n",*nbreDeTypeDeSur);
     //  printf("N  %d\n",*N);
       //  printf("N  %d\n",*M);
      fgets ( line, sizeof line, file );
      fgets ( line, sizeof line, file );
        // Remplir les capteurs

      for( L = 0; L < *N; L++)
      {

         k=0;
         C=0;
         i=0;
         fgets ( line, sizeof line, file );
         for( j = 0; line[j]!='\n'; j++)
         {
             if( line[j]!= ' ')
             {
                 S[k] = line[j];
                 k++;
             }
             else
             {

                S[k]='\0';
                k=0;
                C++;
                if(C==1)
                {
                    Cap[L].rayon = atof(S);
                     // printf("rayon %d  %lf ",L, Cap[L].rayon);
                }
                else if(C==2)
                {
                    Cap[L].duree = atof(S);
                    //printf("duree  %lf ", Cap[L].duree);
                }
                else if(C==3)
                {
                    Cap[L].prix = atof(S);
                     //printf("prix  %lf ", Cap[L].prix);
                }
                else if(C==4)
                {
                    Cap[L].typeSurveillance = S[0];
                }
                else{
                    Cap[L].distance[i] = atof(S);
                     //printf("D%d  %lf ",i, Cap[L].distance[i]);
                    i++;
                }

             }

         }

         S[k] = '\0';

         //Cap[L].distance[i]= atoi(S);
         //printf("D%d  %lf ",i, Cap[L].distance[i]);
         Cap[L].id=L;
      }
printf("\n");
            k=0;

         i=0;
        fgets ( line, sizeof line, file );
        fgets ( line, sizeof line, file );
         for( j = 0; line[j]!='\n'; j++)
         {
             if( line[j]!= ' ')
             {
                 S[k] = line[j];
                 k++;
             }
             else
             {

                S[k]='\0';
                k=0;
                    survTarget[i]= S[0];
                    i++;
             }

         }
      S[k] = '\0';
      survTarget[i]= S[0];
      fclose ( file );
   }
   else
   {
       printf("Error !!! \n");
      perror ( S ); /* why didn't the file open? */
   }

}
void Affiche(Capteur C[],int N,int M)
{
    // Role:
    //Afficher les caracteristiques des capteurs

    int i,j;

    for(i=0; i < N;i++)
    {
        printf("*** Capteur %d *** : \n",i);
         printf("\n");
        printf("Rayon %lf\n", C[i].rayon);
        printf("Duree  %lf\n", C[i].duree);
        printf("Prix  %lf\n", C[i].prix);
        for(j=0; j<M;j++)
        {
            printf("Distance %d : %lf\n",j+1, C[i].distance[j]);
        }
        printf("\n");
    }
}
void Calculer_delta(Capteur C[],int delta[NC][NT], char typeTarget[NT],int N,int M)
{
    //Role:
    //A partir de les diffrentes distances d'un capteur particulier on peut construire une ligne de delta.
    //Retourne la matrice "delta" .
    //Les lignes de la matrice presente les capteurs.
    //les colonnes de la matrice presente les targets.
    //losqu'on met par exemple 1 dans la case(1,1)  c'est_a_dire le capteur un couvre la target 1 .

    int i,j,test;

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {//if((  C[i].distance[j]<=C[i].rayon)&&(C[i].typeSurveillance==typeTarget[j]))
            if(C[i].distance[j]<=C[i].rayon)
            {
                delta[i][j]=1;
            }
            else
            {
                delta[i][j]=0;
            }

        }

    }


}
int HAS_INT(int max)
/*
Rôle : choisir aléatoirement un entier entre 0 et max-1
Paramètres :
	max : définit la borne sup à ne pas dépasser
Résultat : le nombre choisi aléatoirement
*/
{
	int a;

	a=((int) (rand()%1000)*max/1000);
	return(a);
}
int HAS_Float(int max)
/*
Rôle : choisir aléatoirement un entier entre 0 et max-1
Paramètres :
	max : définit la borne sup à ne pas dépasser
Résultat : le nombre choisi aléatoirement
*/
{
	float a;

	a=((float) (rand()%1000)*max/1000);
	return(a);
}
void Afficher_duree_capteur_total(Capteur C[],double D[NC],int N,int M)
{
    //Role:
    //On met dans le tableau D  toutes les durees de vie de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("D:\n");
    for(i=0;i<N;i++)
    {
        D[i]=C[i].duree;
        printf( "%lf  ",D[i]);
    }
    printf("\n");
}
void Afficher_prix_capteur_total(Capteur C[],double P[NC],int N,int M)
{
    //Role:
    //On met dans le tableau P touts les prix de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("Prix:\n");
    for(i=0;i<N;i++)
    {
        P[i]=C[i].prix;
        printf( "%lf  ",P[i]);
    }
    printf("\n");
}
void Afficher_typesurv_capteur_total(Capteur C[],char typesurveillance[NC],int N,int M)
{
    //Role:
    //On met dans le tableau P touts les prix de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("type de surveillance:\n");
    for(i=0;i<N;i++)
    {
        typesurveillance[i]=C[i].typeSurveillance;
       printf( "%c  ",typesurveillance[i]);
    }
    printf("\n");
}
void Afficher_typesurv_target_total(Capteur C[],char typesurveillanceTarget[NT],int N,int M)
{
    //Role:
    //On met dans le tableau P touts les prix de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("type de surveillance de chaque target:\n");
    for(i=0;i<M;i++)
    {

       printf( "%c  ",typesurveillanceTarget[i]);
    }

    printf("\n");

}


void Afficher_delta(int delta [NC][NT], int N, int M)
{
    //Role:
    //Affiche la matice delta.
    int i,j;

    printf("Delta: \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
          printf("%d ",delta[i][j]);
        }
         printf("\n");
    }
}
void Evaluation(double D[NC],double P[NC],int delta[NC][NT],int N,int M,double *prix_total,double *duree_vie,int *nbreCoverSet)
{
    double P1[NC];
    double D1[NC];
    int ST[NT];
    int coveredTarget=0;
    *nbreCoverSet=0;
    double mini;
    int a,s,i,j,h=0,l;//nbre de cible qu'on peut couvrir dans chaque ligne
    int R[NC];//tableau qui contient les numero de lignes
    *duree_vie=0;
    *prix_total=0;
    *nbreCoverSet=0;
    mini= 100000000;
    printf("The Different Free Disjoint Set Covers :\n");
printf("\n");
    //printf("\n");
      for(a=0;a<N;a++)
                {
                    P1[a]=P[a];
                    D1[a]=D[a];
                }
            l=0;
          for(i=0;i<N;i++)
          {
              if(D1[i]!=0)
                 {
                    R[l]=i;
                    l++;
                   for(j=0;j<M;j++)
                    {
                        if(delta[i][j]==1)
                        {
                            if (existe_tab(ST,j,h)==0)
                            {ST[h]=j;
                            h++;
                                 coveredTarget=coveredTarget+1;
                            }

                        }

                    }//printf(" capteur %d couvre\n",h);
                    if (coveredTarget==M) {

                            *nbreCoverSet=*nbreCoverSet+1;

                            coveredTarget=0;
                            h=0;
                            printf("cover set C%d=",*nbreCoverSet);
                for(s=0;s<l;s++)
                {
                        if(D1[R[s]]<mini)
                        {
                            mini= D1[R[s]];
                        }
                 printf("s%d ",R[s]+1);

                }
 printf(":%lf \n",mini);
                for(s=0;s<l;s++)
                {
                       *prix_total=*prix_total+P1[R[s]];

                        P1[R[s]]=0;
                }
                  //mise a jour de la durée de vie de chaque capteur
                for(s=0;s<l;s++)
                {
                    if(D1[R[s]]!=0)
                    {
                        D1[R[s]]=0;
                       // D1[R[s]]=D1[R[s]]-mini;
                       // printf("duree restante du capteur%d :%lf\n",R[s],D[R[s]]);
                    }
                }
                *duree_vie= *duree_vie+mini;
                l=0;
                    }
                 }
            }
}
    int existe_tab(int T[NT+1],int element,int N)
{
    /* Role : Tester si le nombre n existe dqns le tqbleaux T */
    int i;
    for(i=0;i<N;i++)
        if(T[i]==element)
        return 1;
    return 0;

}

double timevaldiff(struct timeval *starttime, struct timeval *finishtime)
{
  double msec;
  msec=(finishtime->tv_sec-starttime->tv_sec)*1000;
  msec+=(finishtime->tv_usec-starttime->tv_usec)*1.0/1000;
  return msec;
}
int main(int argc, char *argv[])
{
    Capteur C[NC];
    int delta[NC][NT];
    double D[NC];
    double P[NC];
    char typesur[NC];
    double msec;
    struct timeval start, finish;
    int N;//Nombre de capteurs.
    int M;//Nombre de targets.
    int area;
    int range;
    int prix;
    int Emax;
    int Emin;
    time_t t;
    int average;
    float RS[NC];
    float E[NC];
    float PR[NC];
    int XS[NC];
    float YS[NC];
    float XT[NT];
    float YT[NT];
    float Distance[NC][NT];
    double L[200];
    int nbreTypSur;//Nombre de type de surveillance
    double duree_vie;//durée de vie.
    double prix_total;//prix total.
    int nbreCoverSet;//nombre de cover set.
    unsigned int graine;
    double Cmax[1000];
    char survTarget[NT];
    char typesurTarget[NT];
    char line[10000];
    double averageLifeTime=0;
    double averageenergie=0;
    double averagemsec=0;
    static const char result[] = "result.txt";
   //static const char filename[] = "test7Heterogene.txt";
   static const char *filename[1000];
   static const char *filename1[1000];
    /* fichier  pour lire les donnees */
    graine=atoi(argv[1]);
    N=atoi(argv[2]);
    M=atoi(argv[3]);
    Emax=atoi(argv[4]);
    Emin=atoi(argv[5]);
    area=atoi(argv[6]);
    range=atoi(argv[7]);
    prix=atoi(argv[8]);
    filename[0]= argv[9];
    average=atoi(argv[10]);
    filename1[0]= argv[9];
   /* int i;

    for (i=0; i < argc; i++)
    {
        printf("Argument %ld : %s \n", i+1, argv[i]);
    }
    printf("n %ld",area);*/
    srand(graine);
    FILE* fichier = NULL;
    printf("average= %d",average);
    fichier = fopen(result , "a+");
    char e[10];
    for (int i=0; i < average; i++)
    {
    //strcat(filename[0],"_");
    jeuxInstance(N,M,Emax,Emin,prix,PR,area,range,E,RS,XS,YS,XT,YT,Distance,filename[0]);

    lire_Data(C,&N,&M,filename[0],&survTarget,&nbreTypSur);
    filename[0]=filename1[0];
    printf("Nombre de capteurs:  %d\n",N);
    printf("Nombre de cibles:  %d\n",M);
    for(int j=0; j < N; j++)
    {
      averageenergie=averageenergie+E[j];
    }
     averageenergie=averageenergie/N;
    Affiche(C,N,M);
    Calculer_delta(C,delta,survTarget,N,M);
    Afficher_delta(delta,N,M);
    //getchar();
    //getchar();
    printf(" Nombre de type de surveillance: %d\n",nbreTypSur);
    //getchar();
    //getchar();
    Afficher_duree_capteur_total(C,D,N,M);
    printf("\n");
    Afficher_prix_capteur_total(C,P,N,M);
    printf("\n");
    Afficher_typesurv_capteur_total(C,typesur,N,M);
    Afficher_typesurv_target_total(C,survTarget,N,M);
    printf("\n");
    gettimeofday(&start, NULL);
    Evaluation(D,P,delta,N,M,&prix_total,&duree_vie,&nbreCoverSet);
    gettimeofday(&finish, NULL);
    msec = timevaldiff(&start, &finish);
    L[i]=duree_vie;
    averageLifeTime=averageLifeTime+duree_vie;
    averagemsec=averagemsec+msec;
    }
    if (fichier != NULL)
    {
     fputs("Graine=", fichier);
     sprintf (line, " %d;", graine);
     fputs(line,fichier);
     fputs("Number of sensors=", fichier);
     sprintf (line, " %d;", N);
     fputs(line,fichier);
     fputs("Number of targets=", fichier);
     sprintf (line, " %d;", M);
     fputs(line,fichier);
     fputs("The average energy=", fichier);
     sprintf (line, " %f;", averageenergie);
     fputs(line,fichier);
     fputs("The number of cover set=", fichier);
     sprintf (line, " %d;", nbreCoverSet);
     fputs(line,fichier);
     fputs("The HWSN lifetime=", fichier);
     sprintf (line, " %f;", L[0]);
     fputs(line,fichier);
     fputs("The average HWSN lifetime=", fichier);
     sprintf (line, " %f;", averageLifeTime/average);
     fputs(line,fichier);
     fputs("The execution times=", fichier);
     sprintf (line, " %f;", (averagemsec/average)/1000);
     fputs(line,fichier);
     fputs("The average=", fichier);
     sprintf (line, " %d",average);
     fputs(line,fichier);
     fputs("\n",fichier);
     fclose(fichier);
    }
    printf("*****************The end ******************************* \n");
    printf("the  average HWSN lifetime is %lf\n",averageLifeTime/average);
    printf("The average The execution timesexecution times =%lf seconde \n",(averagemsec/average)/1000);
    //getchar();
    return EXIT_SUCCESS;
    //getchar();
    //getchar();
}
