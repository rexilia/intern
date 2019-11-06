import java.io.*;
import java.util.Scanner; 
class main { 
    static Scanner scan=new Scanner(System.in);
	public static void main(String[] args) throws IOException 
	{ 
	    String path,key,destination;
	    int index;
	    path=scan.nextLine();
	    key=scan.nextLine();
	    destination=scan.nextLine();
		File dir = new File(path); 

		PrintWriter pw = new PrintWriter(destination); 

		String[] fileNames = dir.list(); 

		for (String fileName : fileNames) { 
			//Reading each file

			File f = new File(dir, fileName); 

			BufferedReader br = new BufferedReader(new FileReader(f)); 
			//Copying contents of the file 
			
			Character c;
			while (c != ']') 
			{ 
                do{
                c=br.read();
                pw.print(c);
                }while(c != '[');
			}
			while (c != ']') 
			{ 
                do{
                c=br.nextChar();
                }while(c != '[');
				pw.print(c); 
				c = br.nextChar(); 
			} 
			pw.flush(); 
		}
		String cha="]";
		pw.println(cha);
		//Merging is done
	} 
} 
