#include "AppManager.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"

using namespace std;

AppManager::AppManager(){}

void AppManager::GO(int argc, char** argv)
{
	srand(time(NULL));
	int length, speed, freq, probability, minRadius, maxRadius;
	bool ep;
	//	vector<Line> vec;
	//	vector<Figure*> vecf;
	LinkedList<Figure*> vecf;
	ArrayList<int> arrsec;

	string checklength, checkspeed, checkfreq, epilepsy, checkprob, checkmin, checkmax;

	int counter = 0;

	if (argc == 2)
	{
		string help = argv[1];
		if (!(help.compare("--help")) || !(help.compare("/?")))
		{
			cout << "MATRIX: BEGINNING" << endl;
			cout << "Enter the name of the program, then 4 parameters separated by a space:" << endl;
			cout << "1. Line length (Integer number between 1 and 30);" << endl;
			cout << "2. Line speed (Integer number between 1 and 30);" << endl;
			cout << "3. Line generation frequency (Integer number between 1 and 30);" << endl;
			cout << "4. Epilepsy mode flag (Y or N).";
			exit(0);
		}
	}
	else if (argc == 8)
	{
		int intlen = atoi(argv[1]);
		if (atof(argv[1]) == intlen && intlen >= 1 && intlen <= 30)
		{
			length = atoi(argv[1]);
			counter++;
		}
		int intspeed = atoi(argv[2]);
		if (atof(argv[2]) == intspeed && intspeed >= 1 && intspeed <= 30)
		{
			speed = atoi(argv[2]);
			counter++;
		}
		int intfreq = atoi(argv[3]);
		if (atof(argv[3]) == intfreq && intfreq >= 1 && intfreq <= 30)
		{
			freq = atoi(argv[3]);
			counter++;
		}
		epilepsy = argv[4];
		if (epilepsy.length() == 1)
		{
			if (*argv[4] == 'Y' || *argv[4] == 'y')
			{
				ep = true;
				counter++;
			}
			else if (*argv[4] == 'N' || *argv[4] == 'n')
			{
				ep = false;
				counter++;
			}
		}
		int intprob = atoi(argv[5]);
		if (atof(argv[5]) == intprob && intprob >= 1 && intprob <= 1000)
		{
			probability = atoi(argv[5]);
			counter++;
		}
		int intmin = atoi(argv[6]);
		if (atof(argv[6]) == intmin && intmin >= 1 && intmin <= 10)
		{
			minRadius = atoi(argv[6]);
			counter++;
		}
		int intmax = atoi(argv[7]);
		if (atof(argv[7]) == intmax && intmax >= 1 && intmax <= 10)
		{
			maxRadius = atoi(argv[7]);
			counter++;
		}
	}
	if (counter < 7)
	{
		cout << "MATRIX: BEGINNING" << endl;

		while (true)
		{
			cout << "Enter line length (Integer number between 1 and 30): ";
			cin >> checklength;

			int intlen = atoi(checklength.c_str());
			if (atof(checklength.c_str()) == intlen && intlen >= 1 && intlen <= 30)
			{
				length = atoi(checklength.c_str());
				break;
			}
			cout << "Incorrect value. Try Again." << endl;
		}

		while (true)
		{
			cout << "Enter line speed (Integer number between 1 and 30): ";
			cin >> checkspeed;

			int intspeed = atoi(checkspeed.c_str());
			if (atof(checkspeed.c_str()) == intspeed && intspeed >= 1 && intspeed <= 30)
			{
				speed = atoi(checkspeed.c_str());
				break;
			}
			cout << "Incorrect value. Try Again." << endl;
		}

		while (true)
		{
			cout << "Enter line generation frequency (Integer number between 1 and 30): ";
			cin >> checkfreq;

			int intfreq = atoi(checkfreq.c_str());
			if (atof(checkfreq.c_str()) == intfreq && intfreq >= 1 && intfreq <= 30)
			{
				freq = atoi(checkfreq.c_str());
				break;
			}
			cout << "Incorrect value. Try Again." << endl;
		}

		while (true)
		{
			cout << "Enable epilepsy mode? (Y or N): ";
			cin >> epilepsy;

			if (epilepsy.length() == 1)
			{
				if (epilepsy[0] == 'Y' || epilepsy[0] == 'y')
				{
					ep = true;
					break;
				}
				else if (epilepsy[0] == 'N' || epilepsy[0] == 'n')
				{
					ep = false;
					break;
				}
			}
			cout << "Incorrect value. Try Again." << endl;
		}

		while (true)
		{
			cout << "Enter line explosion probability (Integer number between 1 and 1000): ";
			cin >> checkprob;

			int intprob = atoi(checkprob.c_str());
			if (atof(checkprob.c_str()) == intprob && intprob >= 1 && intprob <= 1000)
			{
				probability = atoi(checkprob.c_str());
				break;
			}
			cout << "Incorrect value. Try Again." << endl;
		}

		while (true)
		{
			cout << "Enter explosion minimal radius (Integer number between 1 and 10): ";
			cin >> checkmin;

			int intmin = atoi(checkmin.c_str());
			if (atof(checkmin.c_str()) == intmin && intmin >= 1 && intmin <= 10)
			{
				minRadius = atoi(checkmin.c_str());
				break;
			}
			cout << "Incorrect value. Try Again." << endl;
		}

		while (true)
		{
			cout << "Enter explosion maximal radius (Integer number between 1 and 10 (> minimal radius)): ";
			cin >> checkmax;

			int intmax = atoi(checkmax.c_str());
			if (atof(checkmax.c_str()) == intmax && intmax >= 1 && intmax <= 10 && intmax >= minRadius)
			{
				maxRadius = atoi(checkmax.c_str());
				break;
			}
			cout << "Incorrect value. Try Again." << endl;
		}
	}

	Windows Win;
	Win.Clear();

	int milliseconds = 0;
	int elapsed;
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	start = chrono::steady_clock::now();
	while (true)
	{
		end = std::chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<chrono::milliseconds>(end - start).count();

		if (elapsed >= milliseconds)
		{
			for (int i = 0; i < freq; i++)
			{
				arrsec.push_back((rand() % 1000) + milliseconds);
			}
			milliseconds += 1000;
		}

		while (!arrsec.empty())
		{
			vecf.push_back(new Line(length, speed, ep, arrsec[0], rand() % (Win.GetWidth() - 1) + 1, probability));
			arrsec.erase(0);
		}

		for (int i = 0; i < vecf.size(); i++)
		{
			if (vecf[i]->GetDestroy())
			{
				vecf.erase(i--);
			}
			else
			{
				vecf[i]->Move(elapsed);
				if (vecf[i]->GetExplode())
				{
					vecf.insert(new Explosion(vecf[i]->GetCurrHeight(), vecf[i]->GetCurrWidth(), minRadius, maxRadius, elapsed), i + 1);
				}
			}
		}
	}
}