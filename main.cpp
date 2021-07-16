#include<stddef.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<netinet/in.h>

void SUM(uint32_t num1, uint32_t num2)
{
    uint32_t sum = num1+num2;
    printf("%d(0x%x)+%d(0x%x)=%d(0x%x)",num1,num1,num2,num2,sum,sum);
}

uint32_t loadFile(char *path)
{
    FILE *fp = fopen(path,"rb");
    uint8_t buffer[4];
    uint32_t *p;
    uint32_t n;
    if(fp==NULL)
    {
        printf("%s is not opened",path);
        return 0;
    }

    fread(&buffer,sizeof(uint8_t),4,fp);

    p=reinterpret_cast<uint32_t *>(buffer);
    n=ntohl(*p);

    return n;
}

int main(int argc, char *argv[])
{
    uint32_t num1,num2;
    num1 = loadFile(argv[1]);
    num2 = loadFile(argv[2]);
    //printf("num1=0x%x\nnum2=0x%x", num1,num2);
    SUM(num1,num2);
    fcloseall();
}
