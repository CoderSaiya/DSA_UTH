using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TSP
{
    internal class ACO
    {
        private int n;
        private int numberOfAnts;
        private double[,] pheromones;
        private double[,] distances;
        private double alpha;
        private double beta;
        private double evaporationRate;
        private Random random;

        public ACO(int numberOfCities, int numberOfAnts, double alpha, double beta, double evaporationRate)
        {
            this.n = numberOfCities;
            this.numberOfAnts = numberOfAnts;
            this.alpha = alpha;
            this.beta = beta;
            this.evaporationRate = evaporationRate;
            this.random = new Random();
            InitializePheromones();
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
                            distances = new double[n, n];
                        }
                        else
                        {
                            for (int i = 0; i < n; i++)
                            {
                                distances[lineNumber - 1, i] = int.Parse(parts[i]);
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
        private void InitializePheromones()
        {
            pheromones = new double[n, n];
            double initialPheromone = 1.0 / (n * n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    pheromones[i, j] = initialPheromone;
                }
            }
        }

        public int[] Solve(int maxIterations)
        {
            int[] bestTour = null;
            double bestTourLength = double.MaxValue;

            for (int iteration = 0; iteration < maxIterations; iteration++)
            {
                int[][] antTours = new int[numberOfAnts][];

                for (int ant = 0; ant < numberOfAnts; ant++)
                {
                    antTours[ant] = ConstructTour();
                }

                UpdatePheromones(antTours);

                // Find the best tour
                for (int ant = 0; ant < numberOfAnts; ant++)
                {
                    double tourLength = CalculateTourDistance(antTours[ant]);
                    if (tourLength < bestTourLength)
                    {
                        bestTourLength = tourLength;
                        bestTour = antTours[ant];
                    }
                }

                EvaporatePheromones();
            }

            return bestTour;
        }

        private int[] ConstructTour()
        {
            int[] tour = new int[n];
            bool[] visited = new bool[n];
            int startCity = random.Next(n);
            tour[0] = startCity;
            visited[startCity] = true;

            for (int i = 1; i < n; i++)
            {
                int nextCity = ChooseNextCity(tour, visited, tour[i - 1]);
                tour[i] = nextCity;
                visited[nextCity] = true;
            }

            return tour;
        }

        private int ChooseNextCity(int[] tour, bool[] visited, int currentCity)
        {
            List<int> possibleCities = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    possibleCities.Add(i);
                }
            }

            double[] probabilities = new double[possibleCities.Count];
            double totalProbability = 0.0;

            for (int i = 0; i < possibleCities.Count; i++)
            {
                int nextCity = possibleCities[i];
                probabilities[i] = Math.Pow(pheromones[currentCity, nextCity], alpha) * Math.Pow(1.0 / distances[currentCity, nextCity], beta);
                totalProbability += probabilities[i];
            }

            // Roulette wheel selection
            double randomValue = random.NextDouble() * totalProbability;
            double cumulativeProbability = 0.0;
            for (int i = 0; i < possibleCities.Count; i++)
            {
                cumulativeProbability += probabilities[i];
                if (cumulativeProbability >= randomValue)
                {
                    return possibleCities[i];
                }
            }

            // If no city is selected (shouldn't happen)
            return possibleCities[random.Next(possibleCities.Count)];
        }

        private void UpdatePheromones(int[][] antTours)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    pheromones[i, j] *= (1.0 - evaporationRate);
                }
            }

            for (int ant = 0; ant < numberOfAnts; ant++)
            {
                double tourLength = CalculateTourDistance(antTours[ant]);
                for (int i = 0; i < n - 1; i++)
                {
                    int city1 = antTours[ant][i];
                    int city2 = antTours[ant][i + 1];
                    pheromones[city1, city2] += 1.0 / tourLength;
                    pheromones[city2, city1] += 1.0 / tourLength;
                }
            }
        }

        private void EvaporatePheromones()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    pheromones[i, j] *= (1.0 - evaporationRate);
                }
            }
        }

        public double CalculateTourDistance(int[] tour)
        {
            double distance = 0.0;
            for (int i = 0; i < n - 1; i++)
            {
                distance += distances[tour[i], tour[i + 1]];
            }
            distance += distances[tour[n - 1], tour[0]]; // Return to the starting city
            return distance;
        }
    }
}
