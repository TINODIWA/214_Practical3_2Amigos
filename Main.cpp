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

    nate.send("Hello from NateDawg", &ctrlCat);
    dom.send("Hello from DommyBoi", &dogorithm);
    luy.send("Hello from Luyanda", &dogorithm);

    return 0;
}