#include "QuizProgram.h"

int Check_Que(int Que_No) {
    while (getline(file1, line))
    {
        cnt++;
        if (line.find("@Q") != std::string::npos && (line.rfind("*", 0) != 0))
        {
            vect.push_back(cnt);
        }
    }
    vect_size = vect.size();
    if (Que_No <= vect_size) {
        return Que_No;
    }
    else if (vect_size == 0)
        return 0;
    else
    {
        cout << "\nYour file only has " << vect.size() << " questions...\nPlease enter a number below that...\n";
        cin >> Number_of_Que;
        Check_Que(Number_of_Que);
    }

}

int Start_the_quiz(istream& file, string line, int answer, int original, int correct, bool check)
{
    option_no = 0;
    while (getline(file, line))
    {
        if (line.find("@E") != std::string::npos)
        {
            std::cout << "\nEnter your answer:  ";

            // std::cout << "The answer you entered is: " << answer <<'\n';
            while (true)
            {
                std::cin >> answer;;
                if (!cin || answer >= option_no || answer <= 0)
                {
                    cout << "\nPlease enter a valid integer as option in between, 1 to " << option_no - 1 << ":  ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else break;
            }
            if (answer == original)
            {
                std::cout << "\nCorrect answer :)";
                correct++;
            }
            else
                std::cout << "\nWrong answer :(";
            Sleep(1500);
            file.clear();
            file.seekg(0, std::ios::beg);
            break;
        }
        if (check == true)
        {
            // std::cin <<"Enter your answer:" << '\n';
            original = stoi(line);
            check = false;
        }
        else if (line.empty() || (line.rfind("*", 0) == 0))
        {
            continue;
        }
        else if (line.find("@A") != std::string::npos)
        {
            std::cout << "\n";
            check = true;
            continue;
        }
        else
        {
            std::cout << line << '\n';
            option_no++;
        }
    }
    return correct;
}

bool Quiz_param() {
    system("CLS");
    std::cout << "\nEnter the questions file name including the extension, to be used for the quiz\n";
    std::cin >> File_path;
    //File_path=Check_file(File_path);
    file1.open(File_path);
    std::cout << "\nEnter the number of questions you would like to attempt as part of the quiz\n";
    std::cin >> Number_of_Que;
    Test_Que = Number_of_Que;
    Number_of_Que = Check_Que(Number_of_Que);
    if (Number_of_Que == 0)
    {
        return true;
    }
    else
        return false;
}





void Proceed_Quiz(istream& file) {
    for (int i = 0; i < Number_of_Que; i++)
    {
        int QueNo = vect[i];
        // std::cout << QueNo << '\n';
        cnt = 0;
        file.clear();
        file.seekg(0, std::ios::beg);
        while (getline(file, line))
        {
            cnt++;
            if (cnt == QueNo)
            {
                system("CLS");
                std::cout << "\nQuestion " << i + 1 << "\n\n";
                correct = Start_the_quiz(file, line, answer, original, correct, check);
            }
        }
    }
}

void results() {
    system("CLS");
    std::cout << "\nHurray, you are done with the quiz and here are your results:";
    std::cout << "\n\nTotal number of questions asked: " << Number_of_Que;
    std::cout << "\n\nTotal number of correct answer : " << correct;
    perc = ((float)correct / Number_of_Que) * 100;
    std::cout << "\n\nPercentage of correct answers: " << perc;
}

void shuff(ifstream& file) {
    unsigned seed = std::chrono::system_clock::now()
        .time_since_epoch()
        .count();
    // auto rng = std::default_random_engine {};
    std::shuffle(std::begin(vect), std::end(vect), std::default_random_engine(seed));
    file.clear();
    file.seekg(0, std::ios::beg);
}

int main()
{
    bool check = false;
    /* Creating input filestream */
    std::cout << "\nWelcome to the Quiz Application, self-test on what you wanted to be tested on ;P";
    Sleep(1500);
    std::cout << "\n\nThis is a timed session...\n\n";
    Sleep(1500);
    string msg = "FASTEN YOUR SEAT BELT...";
    for (int i = 0; i < msg.size(); i++) {
        cout << msg[i];
        Sleep(150);
    }
    Sleep(1000);
    system("CLS");
    std::cout << "\nQuiz Format:-";
    Sleep(1000);
    std::cout << "\n\nThe quiz follows the pattern,\n\nQuestion_Number\n\n@Question\n\n@OPTION1\nOPTION2\n.\n.\n.\nOPTION10 (*at max)";
    Sleep(3000);
    std::cout << "\n\nInput an option number between(1 - Max No. of options available) for an answer";
    Sleep(2000);
    std::cout << "\n\nPress 'Enter' key twice to continue...";
    cin.ignore();
    getchar();
RECHECK: check = Quiz_param();
    auto start = std::chrono::steady_clock::now();
    if (Test_Que == 0) {
        std::cout << "\nmmmmm...";
        Sleep(2000);
        std::cout << "\n\nNot in a mood to take the quiz!?";
        Sleep(2000);
        std::cout << "\n\nSee you back soon... Thank you!!!";
        Sleep(2000);
        return 0;
    }
    else if (Number_of_Que == 0) {
        std::cout << "\nThere seems to be no data in your file or the file name could be wrong\n\nPlease check and reenter the file name again...";
        Sleep(2000);
        goto RECHECK;
        //Sleep(2000);
    //std::cout << "\n\nApplication is closing... Thank you!!!";
        //Sleep(3000);
        //return 0;
    }
    else {
        ifstream file(File_path);
        shuff(file);
        Proceed_Quiz(file);
        results();
        auto end = std::chrono::steady_clock::now();
        cout << "\n\nElapsed time in seconds: "
            << chrono::duration_cast<chrono::seconds>(end - start).count()
            << " sec\n";
        Sleep(5000);
        std::cout << "\n\nPress 'Enter' to exit...";
        cin.ignore();
        getchar();
        system("CLS");
        std::cout << "\n\nHave a good time...See you back soon :)!!!\n";
        Sleep(2000);
        return 0;
    }

}
