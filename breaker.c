#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


int loader(){
    for ( int loop = 0; loop < 4; ++loop) {
        for ( int each = 0; each < 4; ++each) {
            printf ( "\rRetriving usernames%.*s   \b\b\b", each, "***");
            fflush ( stdout);
            sleep (0.9);
        }
    }
    printf ( "\n");
    return 0;
}

int main(int argc , char *argv[1])
{
    char string[255]; int i;
    char *ar;
    char *br;
    char *cr;
loader();



int opt; 
      
     
    



  if(argc == -1)
    {
        printf("Enter the shadow and password");
}

    else

    {

            
      int option;

    while((option = getopt(argc, argv, ":i:d:o:")) != -1)
    {
      switch (option)
      {
      case 'i':
      //printf("Given File: %s\n", optarg);
        ar = optarg;
        break;

      case 'd':
      //printf("Given File: %s\n", optarg);
        br = optarg;

      case 'o':
      cr= optarg;  
      break;
      default:
        break;
      }
    }

        FILE *file_sha = fopen(ar, "r");
        FILE *file_pass = fopen(br,"r");
        FILE *file_out = fopen("cr","w");


          












        if( file_sha ==0 || file_pass == 0 )

        {

            printf("Could not open the file");



        }

        else


        {
                char *xline = NULL;
                char *yline = NULL;

                char username[100];

                char str1[20];
                char str2[20];

                char str3[20];
                char obj[20];

                size_t len1 = 0 , len2 = 0;

                char *output;

                int count=0;

time_t begin = time(NULL);

                while ( getline ( &yline, &len2, file_pass ) != -1 )

                {
                    while (( getline ( &xline, &len1, file_sha)) != -1 )
                    {
                        sscanf(yline,"%s%s%s%s",str1,str2,str3,obj);

                 //       printf("%s",obj);

                        strcpy(username,xline);
                        char *test0 = strtok(username, ":");

                        for(int i=0;i<4;i++)
                            {
                                 test0 = strtok(NULL, ":");

                                 }


                         char *test1 = strtok(xline,":");

                               for(int j=0;j<1;j++)
                            {
                                 test1 = strtok(NULL, ":");

                                 }
                          char *test2 = strtok(yline,"\n");

                        output = crypt(obj, test1);
                        if(strcmp(test1,output) == 0)
                         {
                            //printf("%d. Password found for %s!!! \nPassword is '%s'.. \n",count, test0,line2);
                            count++;
                            
                            printf("Username : %s cracked | \nPassword: %s \n\n",test0,obj);
                           printf("Users cracked so far : %d\n\n",count );
                           
                        fprintf(file_out, "Username : %s cracked | \nPassword: %s \n\n",test0,obj);
                        time_t end = time(NULL);
          
                            }

                            }
                            rewind(file_sha);
                            }
                              }

                    fclose(file_sha);
                    fclose(file_out);
                    fclose(file_pass);
 }
                
                    return 0;
}