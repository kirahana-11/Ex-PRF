#include<stdio.h>
int main(){
	int day, month;
	printf("Nhap ngay:");
	scanf("%d", &day);
	printf("Nhap thang:");
	scanf("%d", &month);
	int max_day;
	switch(month){
		case 1:case 3: case 5: case 7: case 8: case 10: case 12:
		    max_day=31;
		break;
		case 4 :case 6: case 9: case 11:
		    max_day=30; 
		break;
		case 2:
			max_day=28;
		break;
		default:
			printf("Invalid month\n");
			return 1;
	}
	if(day<1||day>max_day)
	{
		printf("Invalid day\n");
		printf("Ngay %d, thang %d hop le.\n", day, month);
		return 0;
	}
}