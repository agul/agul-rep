import java.math.*;
import java.util.*;
import java.io.*;

public class Task implements Runnable {

	public BufferedReader in;
	public StringTokenizer stoken = new StringTokenizer("");
	public PrintWriter out;
	
	public static void main(String[] args) throws IOException {
		new Thread(null, new Task(), "", (1 << 25)).start();
	}

	public void run() {
		try {
			long t1 = System.currentTimeMillis();
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			solve();
			//System.err.println("Time = " + (System.currentTimeMillis() - t1));
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			out.close();
		}
	}

	private void solve() throws IOException{
		
	}

	private int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextString());
	}

	private long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextString());
	}

	private BigInteger nextBigInteger() throws NumberFormatException, IOException {
		return new BigInteger(nextString());
	}

	private String nextString() throws IOException {
		while(!stoken.hasMoreTokens()){
			String st = in.readLine();
			stoken = new StringTokenizer(st);
		}
		return stoken.nextToken();
	}

	private String nextLine() throws IOException {
		return in.readLine();
	}

	class Pair implements Comparable<Pair> {

		int a, b;

		public Pair(int a, int b) {
			this.a = a; 
			this.b = b;
		}

		@Override
		public int compareTo(Pair other) {
			if (a == other.a) return 0;
			if (a > other.a) return 1;
			return -1;
		}
	}

}