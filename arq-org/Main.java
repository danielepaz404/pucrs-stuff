import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int x, i;
        do {

            System.out.println("\nPrograma de Raiz Quadrada - Newton-Raphson"
            +"\nDesenvolvedores: Daniele, Endrew, Henrique, Joao\n");
            System.out.println("\nDigite os parametros x e i para calcular sqrt_nr (x, i) ou -1 para abortar a execucao\n");
            
            x = teclado.nextInt();
            i = teclado.nextInt();
    
            
    
            System.out.println(sqrt(x, i));
        } while(x > 0 && i > 0);
        teclado.close();
    }

    public static int sqrt(int x, int i){
        if(i <= 0)return 1;
        int sqrt = sqrt(x, i-1);
        return (sqrt + x/sqrt)/2;
    }
}