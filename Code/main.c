#include <stdio.h>
#include <string.h>
#include <time.h>

void line()
{
    int i;
    for(i=0;i<40;i++){
        printf("*");delay();
    }
    putchar('\n');
}
void spacebig()
{
    printf("\n\n\n\n\n");
}
void spacesmall()
{
    printf("\n\n");
}
void delay()
{
    int i,j,k,t=300;
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){
            for(k=0;k<t;k++){
                //null
            }
        }
    }
}
void weekday(int temp)
{
    switch(temp){
        case 0:printf("\t周日/Sunday");break;
        case 1:printf("\t周一/Monday");break;
        case 2:printf("\t周二/Tuesday");break;
        case 3:printf("\t周三/Wednesday");break;
        case 4:printf("\t周四/Thursday");break;
        case 5:printf("\t周五/Friday");break;
        case 6:printf("\t周六/Saturday");break;
    }
}
int yeartype(int a)//判断是否闰年，返回值为一年中的天数
{
    int n;
    if( (a%4==0 && a%400==0)||a%400==0){
        n=366;
    }
    else{
        n=365;
    }
    return n;
}
int main()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p =localtime(&timep);

	/*
	** 此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间
    ** p = gmtime(&timep);
	** 把日期和时间转换为格林威治(GMT)时间的函数
	*/
	printf("\nNow the time is:\n");delay();
    printf("\t%d年\t", 1900+p->tm_year);delay();
    printf("%d月", 1+p->tm_mon);delay();
    printf("%d日", p->tm_mday);delay();
    int d=p->tm_wday;
    weekday(d);delay();//函数确定输出周几，英文单词
    putchar('\n');
    printf("\t今年的第 %d天\t", p->tm_yday);delay();//这一年的第几天
    putchar('\n');
    printf("\t%d点", p->tm_hour);delay();
    printf(" %d分", p->tm_min);delay();
    printf(" %d秒",  p->tm_sec);delay();
    printf("\tIsdst: %d\t", p->tm_isdst);//夏令时
    spacesmall();delay();
    line();

/*Identify struct of our love*/
    struct lovetime{
        int year;
        int mon;
        int day;
        int hour;
        int min;
        int sec;
    }love;

/*Identify the moment we fall in love with each other*/
    love.year=2018;love.mon=1;love.day=1;
    love.hour=0;love.min=10;love.sec=0;

/*Calculating dates*/
    int days=yeartype(1900+p->tm_year);//判断是否闰年
    struct lovetime last;
    last.year=p->tm_year-love.year+1900;
    last.mon=p->tm_mon-love.mon+1;
        if(last.year>0){
            last.mon+=12;
        }
    last.day=p->tm_yday;
        if(last.year>0){
            last.day+=last.year*days;//引入变量days=365 or days=366，分别计算平年闰年的天数
        }
    last.hour=(p->tm_hour-love.hour)+last.day*24;
    last.min=(p->tm_min-love.min)+last.hour*24*60;
    last.sec=(p->tm_sec-love.sec)+last.min*24*60*60;

/*Start nue dog */
    spacesmall();
    //printf("The time we fall in love lasts:\n\n");
    char text[50];
    int i;
    strcpy(text,"The time we fall in love lasts:");
    for(i=0;text[i]!='\0';i++){
        printf("%c",text[i]);
        delay();
    }
    printf("\n\n");
    if(last.year==0){
        printf("\tLess than 1\tyear\n\n");
    }
    else{
        printf("\t%d\tyears\n\n",last.year);
    }
    delay();
    printf("\t%d\t\t",last.mon);    delay();delay();
    printf("months\n\n");           delay();delay();
    printf("\t%d\t\t",last.day);    delay();delay();
    printf("days\n\n");             delay();delay();
    printf("\t%d\t\t",last.hour);   delay();delay();
    printf("hours\n\n");            delay();delay();
    printf("\t%d\t",last.sec);      delay();delay();
    printf("seconds\n\n");          delay();
    spacesmall();                   delay();
    line();delay();

	return 0;
}

