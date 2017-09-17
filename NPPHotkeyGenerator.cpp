#include <cstdio>
#include <cstring>

/*
input:
type ctrl alt shift key name content
type:1=command,2=environment
ctrl,alt,shift:0:No 1:Yes
key:A~Z
name:string
content:for command,it will type "\content";for environment,it will type "\begin{content} \end{content}"
*/

void tab(int n)
{
	for(int i=0;i<n*4;i++)
	{
		printf(" ");
	}
}
void typechar(char c)
{
	tab(3);
	printf("<Action type=\"1\" message=\"2170\" wParam=\"0\" lParam=\"0\" sParam=");
	if(c=='\n')
	{
		printf("\"&#x000A;\"");
	}
	else
	{
		printf("\"%c\"",c);
	}
	printf(" />\n");
}
void typestr(char str[])
{
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		typechar(str[i]);
	}
}
int main()
{
	int type,ctrl,alt,shift;
	char key;
	char name[255],content[255];
	char str[255];
	char yes[]="yes";
	char no[]="no";
	freopen("in.txt","r",stdin);
	freopen("out.xml","w",stdout);
	while(scanf("%d",&type)!=EOF)
	{
		scanf("%d%d%d",&ctrl,&alt,&shift);
		scanf(" %c",&key);
		scanf("%s",name);
		scanf("%s",content);
		tab(2);
		printf("<Macro name=\"%s\" Ctrl=\"%s\" Alt=\"%s\" Shift=\"%s\" Key=\"%d\">\n",name,ctrl==0?no:yes,alt==0?no:yes,shift==0?no:yes,(int)key);
		if(type==1)
		{
			sprintf(str,"\\%s",content);
			typestr(str);
		}
		if(type==2)
		{
			sprintf(str,"\\begin{%s}\n\n\\end{%s}\n",content,content);
			typestr(str);
			tab(3);
			printf("<Action type=\"0\" message=\"2302\" wParam=\"0\" lParam=\"0\" sParam=\"\" />\n");
		}
		tab(2);
		printf("</Macro>\n");
	}
}
