#include <stdio.h>
void menu(){
    printf("  MENU\n");
    printf("1.Square\n");
    printf("2.Cube\n");
    printf("3.Rectangle\n");
    printf("4.Cuboid\n");
    printf("5.Exit\n");
}
class Area{
    private:
       float length;
       float height;
       float breadth;
       public:
       Area() : length(0), breadth(0), height(0) {}
       void setlength(float l){
        length =l;
       }
       void setlb(float l,float b){
        length=l;
        breadth=b;
       }
       void set(float l,float b,float h) {
        length = l;
        breadth =b;
        height =h;
       }
       double squarearea() const {
         return length*length;
       }
       double cubearea() const {
         return 6*length*length;
       }
       double rectanglearea() const {
         return length*breadth;
       }
       double cuboidarea() const {
         return 2* (length*breadth+ breadth*height+ height*length);
       }
};
int main(){
    Area Ar;
    float l,b,h;
    int choice;
    menu();
    printf("Enter a number from 1 to 5:");
    scanf("%d",&choice);
    while(choice>=1 and choice<=5){
        switch(choice){
            case 1:
               printf("Enter side:");
               scanf("%f",&l);
               Ar.setlength(l);
               printf("Area of square is:%f\n",Ar.squarearea());
               break;
            case 2:
               printf("Enter side:");
               scanf("%f",&l);
               Ar.setlength(l);
               printf("Area of cube is:%f\n",Ar.cubearea());
               break;
            case 3:
               printf("Enter length:");
               scanf("%f",&l);
               printf("Enter breadth:");
               scanf("%f",&b);
               Ar.setlb(l,b);
               printf("Area of rectangle is:%f\n",Ar.rectanglearea());
               break;
            case 4:
               printf("Enter length:");
               scanf("%f",&l);
               printf("Enter breadth:");
               scanf("%f",&b);
               printf("Enter height:");
               scanf("%f",&h);
               Ar.set(l,b,h);
               printf("Area of a cuboid:%f\n",Ar.cuboidarea());
               break;
        }
        if (choice==5){
            break;
        }
        printf("Enter a number from 1 to 5:");
        scanf("%d",&choice);
    }
    return 1;
}    