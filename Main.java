import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		String inpt = new String();
		ArrayList<String> grp = new ArrayList<String>();
		Scanner scanner = new Scanner(System.in);
		inpt = scanner.nextLine();
		String[] str = inpt.split("\\s");
		String x = new String();
		for(int j=0; j<str.length; ++j)
		{
			x = str[j];
			for(int i=0; i<x.length(); ++i)
			{
				if (!(((int)x.charAt(i) >= 65 && (int)x.charAt(i) <= 90) || ((int)x.charAt(i) >= 97 && (int)x.charAt(i) <= 122)))
				{
					x = x.replace(x.charAt(i)+"", "");
				}
			}
			if(x.length()>=1)
				grp.add(x.toLowerCase());
		}
		Set<String> LHS = new LinkedHashSet<String>();
		
		for(int i=0; i<grp.size(); ++i)
			LHS.add(grp.get(i));
		
		Map<Character, Integer> tm = new HashMap<Character, Integer>();
		
		for(int i=97; i<123; ++i)
			tm.put((char)i, 0);
		
		for(String elem: grp)
			tm.put(elem.charAt(0), tm.get(elem.charAt(0))+1);
		
		grp.clear();
		
		for(String elem: LHS)
			grp.add(elem);
		
		System.out.println(grp);
		Collections.sort(grp);
		System.out.println(grp);
		
		Comparator<String> cmp = new Comparator<String>()
		{
			public int compare(String s1, String s2)
			{
				if(s1.length()>s2.length() || s1.length()<s2.length())
					return s1.length()-s2.length();
				else
					return s1.compareTo(s2);
			}
		};
		
		Collections.sort(grp, cmp);
		System.out.println(grp);
		System.out.println(tm);
		scanner.close();
	}
}