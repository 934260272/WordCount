#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CountW(char *filename);
int CountC(char *filename);

int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {

        if((fp=fopen(argv[2],"r"))==NULL)
        	{  
        		printf("没有该文件\n");
        		scanf("%s %s %s"  ,argv[0],argv[1],argv[2]);
        		continue;
        	}
        else if(!strcmp(argv[1],"-w")) 
        	{ 
        		CountW(argv[2]);                
        	} 
		else if(!strcmp(argv[1],"-c"))  
        	{ 
				CountC(argv[2]);     
        	} 
		printf("\n");
        scanf("%s %s %s"  ,argv[0],argv[1],argv[2]);
    }
    return 0;
}

int CountW(char *filename)
{  
	FILE *fp;
    char buffer[1000];
    char w;
    int bufferlen=0;
    int isLastBlank=0; 
    int Wcount=0;
    if((fp=fopen(filename,"rb"))==NULL)
	{
        printf("文件不能打开\n");
        exit(0);
    }
	while(fgets(buffer,1000,fp)!=NULL)
	{	
        bufferlen=strlen(buffer);
        for(int i=0;i<bufferlen;i++)
		{
            w=buffer[i];
            if(w==' ' || w==',')
			{
                if(isLastBlank==0)
				{
                    Wcount++;
                }
                isLastBlank=1;
            }
			else if(w!='\n'&&w!='\r')
			{
                isLastBlank=0;
            }
 
        } 
        if(isLastBlank==0)
        	Wcount++;
        	isLastBlank=1;
    }
    fclose(fp); 
		printf("单词数：%d\n"  ,Wcount);                     	
}
int CountC(char *filename)
	{   
		FILE *fp;
		int Ccount=0;
    	fp = fopen(filename, "r");
    	char c;
    	if(NULL==(fp=fopen(filename,"r")))
    		{
        		Ccount=0;
    		}
    	while (!feof(fp))
    		{
        		c=fgetc(fp);
                Ccount++;
    		}
    		
    	fclose(fp);
		printf("字符数:%d\n"  ,Ccount-1);
	}
	


