import java.math.BigInteger;
import java.util.Scanner;
public class Main
{
    public static boolean judge(String num)
    {
        int n = num.length();
        for (int i = 0;i < n / 2;i++)
            if (num.charAt(i) != num.charAt(n - i - 1))
                return false;
        return true;
    }
    public static String change(String num)
    {
        String str = new String("");
        int n = num.length();
        for (int i = n - 1;i >= 0;i--)
            str = str + num.charAt(i);
        return str;
    }
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigInteger t = cin.nextBigInteger();
        int K = cin.nextInt(), i = 0;
        cin.close();
        for (i = 0;i <= K;i++) {
            if (i == K) {
                System.out.println(t);
                System.out.println(i);
                return;
            }
            if (judge(t.toString())) {
                System.out.println(t);
                System.out.println(i);
                return;
            }
            t = t.add(new BigInteger(change(t.toString())));
        }
        return;
    }
}
