import java.util.Scanner;
import java.util.Vector;


public class Main {
    static int sizeOfMatrix;
    static int[][] matrix =  new int[sizeOfMatrix][sizeOfMatrix];
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        sizeOfMatrix = cin.nextInt();

        //Vector<Vector<Integer>> matrix = new Vector<Vector<Integer>>(sizeOfMatrix);
        for (int i =  0; i < sizeOfMatrix; i++) {
            for (int j = 0; j < sizeOfMatrix; j++) {
                int a = cin.nextInt();
                matrix[i][j] = a;
            }
        }

    }

    public static boolean dfs(int element, int parent) {
        boolean[] used = new boolean[sizeOfMatrix];

        for (int node : matrix[element]) {
            if ((node != parent) && (used[node] || !dfs(node, element)))
                return false;
        }

        return true;
    }
}