import java.util.*;
class Main{
	int pow(int x,int y){
		if(y==0)
			return 1;
		if(y==1)
			return x;
		int temp=pow(x,y/2);
		if(y%2==0)
			return temp*temp;
		else
			return x*temp*temp;
	}
	public static void main(String[] args){
		Main obj=new Main();
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		System.out.println(obj.pow(a,1)+obj.pow(a,2)+obj.pow(a,3));
	}
}