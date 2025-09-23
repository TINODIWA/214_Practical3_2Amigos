#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Users.h"
#include "ChatRoom.h"
#include "Nathan.h"
#include "Dominiqu.h"
#include "Luyanda.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    CtrlCat ctrlCat;
    Dogorithm dogorithm;

    Nathan nate(&ctrlCat);
    Dominiqu dom(&dogorithm);
    Luyanda luy(&dogorithm);

    ctrlCat.registerUser(&nate);
    dogorithm.registerUser(&dom);
    dogorithm.registerUser(&luy);

    nate.send("Hello chat", &ctrlCat);
    dom.send("Hello Anyone online", &dogorithm);
    luy.send("Hello Dom, I am, wanna game?", &dogorithm);

    for(string m1 : dogorithm.getChatHistory())
    {
        cout << m1 << endl;
    }

    dom.receive("Hello Anyone online", &dom, &dogorithm);
    luy.receive("Hello Dom, I am, wanna game?", &luy, &dogorithm);

    cout << "\nDogorithm Chat History:" << endl;
    for(string m2 : dogorithm.getChatHistory())
    {
        
        cout << m2 << endl;
    }

    return 0;
}