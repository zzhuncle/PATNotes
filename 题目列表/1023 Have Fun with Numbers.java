import java.math.BigInteger;
import java.util.*;//常用java包
public class Main
{
    public static int used[];//数组声明方法
    public static void main(String args[])
    {
        used = new int[10];
        Arrays.fill(used, 0);//数组初始化方法
        Scanner cin = new Scanner(System.in);
        BigInteger bi = cin.nextBigInteger();//读入整数
        String str1 = bi.toString();
        for (int i = 0;i < str1.length();i++)
            used[str1.charAt(i) - '0']++;
        bi = bi.add(bi);//大整数相加
        String str2 = bi.toString();
        for (int i = 0;i < str2.length();i++)
            used[str2.charAt(i) - '0']--;
        boolean flag = true;
        for (int i = 0;i < 10;i++)
            if (used[i] != 0)
                flag = false;
        System.out.println(str1.length() == str2.length() && flag ? "Yes" : "No");//注意判断是否有进位
        System.out.println(bi);
        return;
    }
}
