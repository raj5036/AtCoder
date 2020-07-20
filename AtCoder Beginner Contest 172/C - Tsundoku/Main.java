import java.util.*;
public class Main{
	void function(Stack<Integer> A,Stack<Integer> B,int N,int M,int K){
		if(K<A.peek() && K<B.peek()){
			System.out.println(0);
			return;
		}
		int time=0,countOfBooks=0;
		while(!A.isEmpty() || !B.isEmpty()){
			if(A.isEmpty())
				time+=B.pop();
			else if(B.isEmpty())
				time+=A.pop();
			else{
				int a=A.peek();
				int b=B.peek();
				if(a<b)
					time+=A.pop();
				else
					time+=B.pop();
			}
			
			countOfBooks++;

			if(time>=K)
				break;
		}

		System.out.println(countOfBooks);
	}
	public static void main(String[] args){
		Main obj=new Main();
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int K=sc.nextInt();
		Stack<Integer> A=new Stack<>();
		for(int i=0;i<N;i++){
			int temp=sc.nextInt();
			A.push(new Integer(temp));
		}
		Stack<Integer> B=new Stack<>();
		for(int i=0;i<M;i++){
			int temp=sc.nextInt();
			B.push(new Integer(temp));
		}
		obj.function(A,B,N,M,K);
	}
}