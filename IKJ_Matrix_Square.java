//package Java_Matrix;
//
//import java.util.Scanner;
//
//public class IKJ_Matrix {
//
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        System.out.println("n 입력 : ");
//        int num = sc.nextInt();
//        int[][] A_Matrix = new int[num][num];
//        int[][] B_Matrix = new int[num][num];
//        int[][] Result_Matrix = new int[num][num];
//
//        // 난수 대입
//        int i,j,k;
//        for(i = 0; i < num; ++i) {
//            for(j = 0; j < num; ++j) {
//                A_Matrix[i][j] = (int)(Math.random() * 10.0D) + 1;
//                B_Matrix[i][j] = (int)(Math.random() * 10.0D) + 1;
//                Result_Matrix[i][j] = 0;
//            }
//        }
//
//        System.out.println("0 부터 9까지의 난수 대입");
//        System.out.println();
//        System.out.println("A Matrix");
//        System.out.println("B Matrix");
//        double start = (double)System.currentTimeMillis();
//
//        // 행렬곱 연산
//        for(i = 0; i < num; i++) {
//            for(k = 0; k < num; k++) {
//                for(j = 0; j < num; j++) {
//                    Result_Matrix[i][j] += A_Matrix[i][k] * B_Matrix[k][j];
//                }
//            }
//        }
//
//        double end = (double)System.currentTimeMillis();
//        /*
//        // 출력문
//        for(i=0;i<num;i++){
//            for(j=0;j<num;j++){
//                System.out.print(Result_Matrix[i][j]+"\t");
//            }
//            System.out.println();
//        }
//        */
//
//        double Result_Time = (end - start) / 1000.0D;
//        System.out.println("실행시간 : " + Result_Time);
//        sc.close();
//    }
//}
