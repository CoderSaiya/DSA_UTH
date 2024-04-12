using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace TSP
{
    public class TSP
    {
        private static int[] visited;
        private static int[,] distance;
        private static int[] result;
        private static int[] a;
        private static int sumD;
        private static int n;
        private static int min;
        public TSP()
        {
            sumD = 0;
            visited = new int[0];
            distance = new int[0,0];
            result = new int[0];
            a = new int[0];
            min = int.MaxValue;
            n = 0;
        }
        public void readFile(string file_name)
        {
            try
            {
                using (StreamReader reader = new StreamReader(file_name))
                {
                    string line;
                    int lineNumber = 0;
                    while ((line = reader.ReadLine()) != null)
                    {
                        string[] parts = line.Split('\t');
                        if (lineNumber == 0)
                        {
                            n = int.Parse(parts[0]);
                            distance = new int[n, n];
                            visited = new int[n];
                            result = new int[n];
                            a = new int[n];
                        }
                        else
                        {
                            for (int i = 0; i < n; i++)
                            {
                                distance[lineNumber - 1, i] = int.Parse(parts[i]);
                            }
                        }
                        lineNumber++;
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
        public void printMatrix()
        {
            for (int i = 0; i < distance.GetLength(0); i++)
            {
                for (int j = 0; j < distance.GetLength(1); j++)
                {
                    Console.Write(distance[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }
        public void PrintSolution1()
        {
            Console.WriteLine("Chi phi: " + (min + distance[result[result.Length - 1], 0]));
            Console.Write("Duong di: ");
            foreach (int id in result)
            {
                Console.Write(id + " -> ");
            }
            Console.WriteLine(0);
        }
        public void PrintSolution2()
        {
            Console.WriteLine("Chi phi: " + sumD);
            Console.Write("Duong di: ");
            foreach (int id in result)
            {
                Console.Write(id + " -> ");
            }
            Console.WriteLine(0);
        }
        public void vetCan(int i)
        {
            TimeSpan timeLimit = TimeSpan.FromSeconds(60);
            DateTime startTime = DateTime.Now;
            for (int j = 1; j < n; j++)
            {
                if (DateTime.Now - startTime > timeLimit)
                {
                    Console.WriteLine("Qua thoi gian!");
                    return;
                }
                if (visited[j] == 0)
                {
                    a[i] = j;
                    sumD += distance[a[i - 1], a[i]];
                    visited[j] = 1;
                    if (i == n - 1)
                    {
                        if (sumD < min)
                        {
                            Array.Copy(a, result, a.Length);
                            min = sumD;
                        }
                    }
                    else
                    {
                        vetCan(i + 1);
                    }
                    sumD -= distance[a[i - 1], a[i]];
                    visited[j] = 0;
                }
            }
        }
        public void thamLam()
        {
            result[0] = 0;
            visited[0] = 1;

            for (int i = 1; i < n; i++)
            {
                int nearestCity = -1;
                min = int.MaxValue;
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && distance[result[i - 1], j] < min)
                    {
                        nearestCity = j;
                        min = distance[result[i - 1], j];
                    }
                }

                if (nearestCity != -1)
                {
                    result[i] = nearestCity;
                    visited[nearestCity] = 1;
                    sumD += min;
                }
            }
            sumD += distance[result[n - 1], 0];
        }
    }
    
    public class Program
    {

        public static void Main(string[] args)
        {
            //1
            //vet can
            Stopwatch stopwatch = new Stopwatch();
            TSP vetCan = new TSP();
            vetCan.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\dataset.txt");
            vetCan.printMatrix();
            Console.WriteLine("\nTHUAT TOAN VET CAN\n");
            stopwatch.Start();
            vetCan.vetCan(1);
            stopwatch.Stop();
            vetCan.PrintSolution1();
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            //tham lam
            Console.WriteLine("\nTHUAT TOAN THAM LAM\n");
            TSP thamLam = new TSP();
            thamLam.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\dataset.txt");
            stopwatch = Stopwatch.StartNew();
            thamLam.thamLam();
            stopwatch.Stop();
            thamLam.PrintSolution2();
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            // ACO
            int numberOfCities = 5;
            int numberOfAnts = 10;
            double alpha = 1.0;
            double beta = 2.0;
            double evaporationRate = 0.5;

            Console.WriteLine("\nTHUAT TOAN ACO\n");
            ACO aco = new ACO(numberOfCities, numberOfAnts, alpha, beta, evaporationRate);
            aco.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\dataset.txt");
            stopwatch = Stopwatch.StartNew();
            int[] bestTour = aco.Solve(100);
            stopwatch.Stop();

            Console.WriteLine("Chi phi: " + aco.CalculateTourDistance(bestTour));
            Console.Write("Duong di: ");
            foreach (int city in bestTour)
            {
                Console.Write(city + " -> ");
            }
            Console.WriteLine(0);
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            //2
            //vet can
            vetCan = new TSP();
            vetCan.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\Dataset2.txt");
            vetCan.printMatrix();
            Console.WriteLine("\nTHUAT TOAN VET CAN\n");
            stopwatch = Stopwatch.StartNew();
            vetCan.vetCan(1);
            stopwatch.Stop();
            vetCan.PrintSolution1();
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            //tham lam
            Console.WriteLine("\nTHUAT TOAN THAM LAM\n");
            thamLam = new TSP();
            thamLam.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\Dataset2.txt");
            stopwatch = Stopwatch.StartNew();
            thamLam.thamLam();
            stopwatch.Stop();
            thamLam.PrintSolution2();
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            //ACO
            numberOfCities = 10;
            Console.WriteLine("\nTHUAT TOAN ACO\n");
            aco = new ACO(numberOfCities, numberOfAnts, alpha, beta, evaporationRate);
            aco.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\Dataset2.txt");
            stopwatch = Stopwatch.StartNew();
            bestTour = aco.Solve(100);
            stopwatch.Stop();

            Console.WriteLine("Chi phi: " + aco.CalculateTourDistance(bestTour));
            Console.Write("Duong di: ");
            foreach (int city in bestTour)
            {
                Console.Write(city + " -> ");
            }
            Console.WriteLine(0);
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            //2
            //vet can
            vetCan = new TSP();
            vetCan.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\dataset3.txt");
            vetCan.printMatrix();
            Console.WriteLine("\nTHUAT TOAN VET CAN\n");
            stopwatch = Stopwatch.StartNew();
            vetCan.vetCan(1);
            stopwatch.Stop();
            vetCan.PrintSolution1();
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            //tham lam
            Console.WriteLine("\nTHUAT TOAN THAM LAM\n");
            thamLam = new TSP();
            thamLam.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\dataset3.txt");
            stopwatch = Stopwatch.StartNew();
            thamLam.thamLam();
            stopwatch.Stop();
            thamLam.PrintSolution2();
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");

            //ACO
            numberOfCities = 15;
            Console.WriteLine("\nTHUAT TOAN ACO\n");
            aco = new ACO(numberOfCities, numberOfAnts, alpha, beta, evaporationRate);
            aco.readFile("C:\\Users\\admin\\Documents\\WorkSpace\\TKPTGT\\btl\\TSP\\TSP\\dataset3.txt");
            stopwatch = Stopwatch.StartNew();
            bestTour = aco.Solve(100);
            stopwatch.Stop();

            Console.WriteLine("Chi phi: " + aco.CalculateTourDistance(bestTour));
            Console.Write("Duong di: ");
            foreach (int city in bestTour)
            {
                Console.Write(city + " -> ");
            }
            Console.WriteLine(0);
            Console.WriteLine($"Thoi gian chay: {stopwatch.ElapsedTicks} ticks");
        }
    }
}