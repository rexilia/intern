#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
int main() 
{ 
    char key[20],dest_name[20],path[30],destination[20],c,temp[20],file_name[20];
    int index=1;
    char exten[]=".json";
    //get the inputs
    printf("Enter the path");
    scanf("%[^\n]%*c", path);
    char original_path[30],dest_path[30];
    original_path=path;
    dest_path=path;
    
    printf("Enter File name key");
    scanf("%s",key);
    char original[20];
    strcpy(original,key);
    
    printf("Enter the destination file name");
    scanf("%s",dest_name);
    strcat(dest_name,exten);
    strcat(dest_path,dest_name);
    FILE *source_file,*destination_file;
    
    while(1)
    {
        strcat(key,index);
        strcat(key,exten);
        strcat(path,key)
        source_file = fopen(path, "r"); 
        if(source_file != NULL)
        {
            //adding the data name in JSON format to the destination_file
            if(index==1)
            {
            char character;
            destination_file = fopen(dest_path, "w");
            while ((character = fgetc(source_file)) != '[')
            fputc(character, destination_file);
            }
            //merging contents
            do{
            c=fgetc(source_file);
            }while(c != '[');
             
            while ((c = fgetc(source_file)) != ']') 
	            fputc(c, destination_file);
        }
        else
        {
            break;
        }
        //Re-initializing key
        index++;
        for(int ind=0;key[ind] != '\0';ind++)
        strcpy(&key[ind],"\0");
        for(int ind=0;path[ind] != '\0';ind++)
        strcpy(&path[ind],"\0");
        strcpy(key,original);
        strcpy(path,original_path);
        fclose(source_file); 
        fclose(destination_file); 
}
char additional[]="]}";
fputs(additional,destination_file);
printf("Merged files Successfully"); 
return 0; 
} 
