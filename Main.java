import java.util.*; //Very useful inbuil library
import Network.*;

public class Main
{

	public static void main(String[] args)
	{
		network N = new network();
		phone p1 = new phone(12345, "TI");
		smart_phone p2 = new smart_phone(23456, "Samsung", "Mediatek");
		smart_phone p3 = new smart_phone(13452, "Apple", "Apple");
		p1.connect(N);
		p2.connect(N);
		p3.connect(N);
		p1.call(23456);
		p3.call(12345);
		p2.hang();
		p3.call(12345);
	}

}
