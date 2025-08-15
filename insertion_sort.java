public class Main {
    public static void main(String[] args) {
        int a[]={5,1,6,3,2,9,4,7};
        for(int i=1;i<a.length;i++)
        {
            int temp=a[i];
            int j=i-1;
            while(j>=0&& a[j]>temp)
            {
                a[j+1]=a[j];
                j--;
            }
        a[j+1]=temp;    
        }
        for(int i:a)
        {
            System.out.print(i);
        }
        
    }
}
