
#include <stdio.h>
#include <time.h>
void line()
{
    printf("****************************************************************\n");
}
void spacebig()
{
    printf("\n\n\n\n\n");
}
void spacesmall()
{
    printf("\n\n");
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
	printf("\nNow is:\n");
    printf("Year:\t%d\t", 1900+p->tm_year);
    printf("Month:\t%d\t", 1+p->tm_mon);
    printf("Day:\t%d\t", p->tm_mday);
    putchar('\n');
    printf("Hour:\t%d\t", p->tm_hour);
    printf("Minute:\t%d\t", p->tm_min);
    printf("Second:\t%d\t",  p->tm_sec);
    putchar('\n');
    printf("Weekday:%d\t", p->tm_wday);
    printf("Days:\t%d\t", p->tm_yday);//这一年的第几天
    printf("Isdst:\t%d\t", p->tm_isdst);//夏令时
    putchar('\n');
    spacesmall();
    line();

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
    struct lovetime last;
    last.year=p->tm_year-love.year+1900;
    last.mon=p->tm_mon-love.mon+1;
        if(last.year>0){
            last.mon+=12;
        }
    last.day=p->tm_yday;
        if(last.year>0){
            last.day+=last.year*365;//引入变量days=365 or days=366，分别计算平年闰年的天数
        }
    last.hour=(p->tm_hour-love.hour)+last.day*24;
    last.min=(p->tm_min-love.min)+last.hour*24*60;
    last.sec=(p->tm_sec-love.sec)+last.min*24*60*60;

/*Start nue dog */
    spacesmall();
    printf("The time we fall in love lasts:\n\n");
    if(last.year==0){
        printf("\tLess than 1\tyear\n\n");
    }
    else{
        printf("\t%d\tyear\n\n",last.year);
    }
    printf("\t%d\t\tmonths\n\n",last.mon);
    printf("\t%d\t\tdays\n\n",last.day);
    printf("\t%d\t\thours\n\n",last.hour);
    printf("\t%d\tseconds\n\n",last.sec);
    spacebig();
	return 0;
}

