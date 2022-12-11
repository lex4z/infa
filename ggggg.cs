using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace OBAMA_HAMBURGER_SUSSY_BALLS
{
    class IntArray //добавить потом в б модуль
    {
        int[] a;
        int length;
        public bool error = false;

        public IntArray(int size) //конструктор класса
        {
            a = new int[size];
            length = size;
        }
        public IntArray(params int[] arr)
        {
            a = arr;
            length = arr.Length;
        }

        public int Length //свойство длина массива
        {
            get { return length; }
        }

        public int this[int i]  //индексатор
        {
            get
            {
                if (i >= 0 && i < length) return a[i];
                else { error = true; return 0; }
            }
            set
            {
                if (i >= 0 && i < length && value >= 0 && value <= 100) a[i] = value;
                else error = true;

            }
        }
        
        public static IntArray RandomIntArray(int length, int a, int b)
        {
            Random r = new Random();
            IntArray t = new IntArray(length);
            for (int i = 0; i < length; i++) t[i] = r.Next(a, b);
            return t;
        }

        
    }
    class Programm
    {
        static void Main()
        {
            int n = 50;
            //IntArray lf = IntArray.ArrayFromTextFile("test228133714882004322.txt");//("C:\\Users\\aaaa1\\Downloads\\test228133714882004322.txt");
            IntArray lf = IntArray.RandomIntArray(n,0,100);
            for (int i = 0; i < lf.Length; i++)
            {

                //lf[i] = i * 2;
                Console.Write(lf[i] + $"\t");
                if ((i+1) % 10 == 0) Console.WriteLine();
            }
            if (lf.error) Console.Write(" Были ошибки! ");
            Console.ReadKey();
        }

    }
}