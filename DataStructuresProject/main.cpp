#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

///----------------------------- Information ----------------------------------///
/*
                        Starting Date: 24/08/2015
                        Creators: Andrés García Salas
                                  Jose Carlos Rodriguez Arrieta

                        Begin hour: 6:00 pm
*/
///------------------------- Structures Section -------------------------------///

struct Destiny
{
    string place;
    string lenguage;
    string coin;
    struct Destiny *next, *bef;
    struct destinyProgramRelation *firstDPR;
    Destiny(string p, string l, string c)
    {
        place = p;
        lenguage = l;
        coin = c;
        next = NULL;
        bef = NULL;
        firstDPR = NULL;
    }
}*firstDestiny;

struct Program
{
    string id;
    string detail;
    double price;
    struct Program *next;
    struct programDestinyRelation *firstPDR;
    Program(string i, string d, double p)
    {
        id = i;
        detail = d;
        price = p;
        next = NULL;
        firstPDR = NULL;
    }
}*firstProgram;

struct circuit
{
    string id;
    string name;
    struct circuit *next;
    struct circuitProgramDestinyRelation *firstCPDR;
    circuit(string i, string n)
    {
        id = id;
        name = n;
        next = NULL;
        firstCPDR = NULL;
    }
}*firstCircuit;

struct offer
{
  string name;
  struct offer *next;
  struct offerProgramRelation *firstOPR;
  offer(string n)
  {
      name = n;
      next = NULL;
  }
}*firstOffer;

struct user
{
    string id;
    string name;
    string lastName;
    string nationality;
    char gen;
    struct user *next;
    struct coment *firstComent;
    struct userCircuitRelation *firstUCR;
    user(string i, string n, string ln, string nat, char g)
    {
        id = i;
        name = n;
        lastName = ln;
        nationality = nat;
        gen = g;
        next = NULL;
        firstComent = NULL;
        firstUCR = NULL;
    }
}*firstUser;

///---------------------- Final Structures Section -----------------------------///

///---------------------- Sublists Structure Section ---------------------------///

struct destinyProgramRelation
{
    struct Program *programRelation;
    struct destinyProgramRelation *next;
    destinyProgramRelation(struct Program *pR)
    {
        programRelation = pR;
        next = NULL;
    }
};

struct programDestinyRelation
{
struct Destiny *destinyRelation;
struct programDestinyRelation *next;
programDestinyRelation(struct Destiny *dR)
{
    destinyRelation = dR;
    next = NULL;
}
};

struct circuitProgramDestinyRelation
{
    struct Destiny *destinyRelation;
    struct Program *programRelation;
    struct circuitProgramDestinyRelation *next;
    circuitProgramDestinyRelation(struct Destiny *dR, struct Program *pR)
    {
        destinyRelation = dR;
        programRelation = pR;
        next = NULL;
    }
};

struct coment
{
    string comentDescription;
    struct Program *programRelation;
    struct circuit *circuitRelation;
    struct coment *next;
    coment(struct Program *pR, struct circuit *cR, string c)
    {
        programRelation = pR;
        circuitRelation = cR;
        comentDescription = c;
        next = NULL;
    }
};

struct userCircuitRelation
{
    struct circuit *circuitRelation;
    struct userCircuitRelation *next;
    userCircuitRelation(struct circuit *cR)
    {
        circuitRelation = cR;
        next = NULL;
    }
};

struct offerProgramRelation
{
    int quota;
    struct Program *programRelation;
    struct offerProgramRelation *next;
    offerProgramRelation(struct Program *pR)
    {
        programRelation = pR;
        next = NULL;
    }
};

///-------------------- Final Sublists Structure Section -----------------------///

///------------------- Declaration of Apparence's Methods ----------------------///




///---------------- Final Declaration of Apparence's Methods ------------------///

///------------------------------ Searches ------------------------------------///
                //-------------- Lists ----------------//
struct Destiny * searchD(string place)
{
    struct Destiny * temp = firstDestiny;

    if (firstDestiny == NULL)
        return NULL;
    for(;temp != NULL; temp = temp ->next)
    {
        if (temp->place == place)
            return temp;
    }
    return NULL;
}

struct Program * searchP(string id)
{
    struct Program * temp = firstProgram;

    if (firstProgram == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if (temp -> id == id)
            return temp;
    }
    return NULL;
}

struct circuit * searchC(string id)
{
    struct circuit * temp = firstCircuit;

    if (firstCircuit == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        cout<< temp ->id<<"==" << id<<endl;
        if (temp ->id == id)
            return temp;
    }
    return NULL;
}

struct user * searchU(string id)
{
    struct user * temp = firstUser;

    if (firstUser == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if (temp -> id == id)
            return temp;
    }
    return NULL;
}

struct offer * searchO(string id)
{
    struct offer * temp = firstOffer;

    if (firstOffer == NULL)
        return NULL;
    do
    {
        if (temp -> id == id)
            return temp;
        temp = temp -> next;
    }while(temp != firstOffer);

    return NULL;
}

                //-------------- Sub Lists -------------//
struct destinyProgramRelation * searchDPR(struct Destiny *destinyNode, struct Program *programNode)
{
    struct destinyProgramRelation * temp = destinyNode->firstDPR;

    if (destinyNode->firstDPR == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if (temp -> programRelation == programNode)
            return temp;
    }
    return NULL;
}

struct programDestinyRelation * searchPDR(struct Program *programNode, struct Destiny *destinyNode)
{
    struct programDestinyRelation * temp = programNode->firstPDR;

    if (programNode->firstPDR == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if (temp -> destinyRelation == destinyNode)
            return temp;
    }
    return NULL;
}

struct offerProgramRelation * searchOPR(struct offer *offerNode, struct Program *programNode)
{
    struct offerProgramRelation * temp = offerNode->firstOPR;

    if (offerNode->firstOPR == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if (temp -> programRelation == programNode)
            return temp;
    }
    return NULL;
}

struct userCircuitRelation * searchUCR(struct user * userNode, struct circuit *circuitNode)
{
    struct userCircuitRelation * temp = userNode->firstUCR;

    if (userNode->firstUCR == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if (temp -> circuitRelation == circuitNode)
            return temp;
    }
    return NULL;
}

struct circuitProgramDestinyRelation * searchCPDR(struct circuit *circuitNode, struct Program *programNode, struct Destiny *destinyNode)
{
    struct circuitProgramDestinyRelation * temp = circuitNode->firstCPDR;

    if(circuitNode->firstCPDR == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if ((temp -> programRelation == programNode) and (temp -> destinyRelation == destinyNode))
            return temp;
    }
    return NULL;
};

struct coment * searchComment(struct user *userNode, struct Program *programNode, struct circuit *circuitNode, string comment)
{
    struct coment * temp = userNode -> firstComent;

    if(userNode -> firstComent == NULL)
        return NULL;
    for (;temp != NULL; temp = temp ->next)
    {
        if ((temp -> programRelation == programNode) and (temp -> circuitRelation == circuitNode) and (temp -> comentDescription == comment))
            return temp;
    }
    return NULL;
};

///--------------------------- Final Searches ---------------------------------///

///------------------------- Insert Methods ----------------------------------///

                //-------------- Lists ----------------//
bool isAlphabeticallyGreaterThan(string newNode, string temp, int i){
    int x = newNode[i];
    int y = temp[i];

    return ((x > y) ? false : ((x < y) ? true : isAlphabeticallyGreaterThan(newNode, temp, i+1)));
}

void insertDestiny(string id, string name, string detail)
{
    struct Destiny * newNode = new Destiny(id, name, detail);
    struct Destiny * localSearch = searchD(newNode -> id);

    if(localSearch != NULL)
    {
        cout<< "\nThis destiny already exist!...\n";
        return;
    }

    if (firstDestiny == NULL)
    {
        firstDestiny = newNode;
    }else
    {
        struct Destiny * temp = firstDestiny;

        bool alphaOrder = true; // only to initialice.
        int j = 0;

        do
        {
            alphaOrder = isAlphabeticallyGreaterThan(newNode->name, temp->name, 0);

            if (alphaOrder)
            {
                newNode -> next = temp;
                temp -> bef = newNode;
                if(j == 0)
                    firstDestiny = newNode;
            }else if(temp -> next == NULL)
            {
                temp -> next = newNode;
                newNode -> bef = temp;
                alphaOrder = true;
            }
            temp = temp -> next;
            j++;
        }while(alphaOrder == false);
    }
    cout<<"\nData Insert Correctly!...\n";
}

void insertProgram(string id, string name, string description, double price)
{
    struct Program * newNode = new Program(id, name, description, price);
    struct Program * localSearch = searchP(newNode -> id);

    if (localSearch != NULL){
        cout<<"\nThis program already exists!...\n";
        return;
    }

    if(firstProgram == NULL)
        firstProgram = newNode;
    else
    {
        newNode -> next = firstProgram;
        firstProgram = newNode;
    }
    cout<<"\nData Insert Correctly!...\n";
}

void insertUser(string id, string name, string lastName)
{
    struct user * newNode = new user(id, name, lastName);
    struct user * localSearch = searchU(newNode -> id);

    if(localSearch != NULL)
    {
        cout<< "\nThis user already exist!...\n";
        return;
    }

    if (firstUser == NULL)
    {
        firstUser = newNode;
    }else
    {
        struct user * temp = firstUser;

        bool alphaOrder = true; // only to initialice.
        int j = 0;

        do
        {
            alphaOrder = isAlphabeticallyGreaterThan(newNode->name, temp->name, 0);
            struct user * before = firstUser;

            if (alphaOrder)
            {
                newNode -> next = temp;
                if(j == 0)
                    firstUser = newNode;
                else
                {
                    for(; before -> next != temp ;temp = temp -> next){}
                    before->next = newNode;
                }
            }else if(temp -> next == NULL)
            {
                temp -> next = newNode;
                alphaOrder = true;
            }
            temp = temp -> next;
            j++;
        }while(alphaOrder == false);
    }
    cout<<"\nData Insert Correctly!...\n";
}

void insertOffer(string id, string description, double price, int quantity)
{
    struct offer * newNode = new offer(id, description, price, quantity);
    struct offer * localSearch = searchO(newNode -> id);

    if (localSearch != NULL){
        cout<<"\nThis offer already exists!...\n";
        return;
    }

    if(firstOffer == NULL)
    {
        newNode -> next = newNode;
        firstOffer = newNode;
    }else
    {
        newNode -> next = firstOffer;

        struct offer * temp = firstOffer;

        do
        {
            temp = temp -> next;
        }while(temp -> next != firstOffer);

        temp -> next = newNode;
    }
    cout<<"\nData Insert Correctly!...\n";
}

void insertCircuit(string id, string name)
{
    struct circuit * newNode = new circuit(id, name);
    struct circuit * localSearch = searchC(newNode -> id);

    if (localSearch == NULL)
        cout<< "Id a insertar: "<< id <<", id encontrado: NULL"<<endl;
    else
        cout<< "Id a insertar: "<< id <<", id encontrado: "<< localSearch->id<<endl;

    if (localSearch != NULL)
    {
        cout<<"\nThis circuit already exists!...\n";
        return;
    }

    if(firstCircuit == NULL)
        firstCircuit = newNode;
    else
    {
        struct circuit * temp = firstCircuit;

        for(;temp -> next != NULL; temp = temp -> next){}

        temp -> next = newNode;
    }
    cout<<"\nData Insert Correctly!...\n";
}

                //-------------- Sub Lists -------------//
void insertDestinyProgramRelation(string destinyID, string programID)
{
    struct Destiny * destinySearch = searchD(destinyID);
    struct Program * programSearch = searchP(programID);

    if (destinySearch == NULL)
    {
        cout<<"\nThe Destiny doesn't exist!...\n";
        return;
    }

    struct destinyProgramRelation * newNode = new destinyProgramRelation(programSearch);
    struct destinyProgramRelation * localSearch = searchDPR(destinySearch, programSearch);

    if (localSearch != NULL)
    {
        cout<<"\nThis Relation already exists!...\n";
        return;
    }else if(destinySearch->firstDPR == NULL)
        destinySearch->firstDPR = newNode;
    else
    {
        newNode -> next = destinySearch->firstDPR;
        destinySearch->firstDPR = newNode;
    }
    cout<<"\nRelation Insert Correctly!...\n";
}

void insertProgramDestinyRelation(string programID, string destinyID)
{
    struct Program * programSearch = searchP(programID);
    struct Destiny * destinySearch = searchD(destinyID);

    if (programSearch == NULL)
    {
        cout<<"\nThe Program doesn't exist!...\n";
        return;
    }

    struct programDestinyRelation * newNode = new programDestinyRelation(destinySearch);
    struct programDestinyRelation * localSearch = searchPDR(programSearch, destinySearch);

    if (localSearch != NULL)
    {
        cout<<"\nThis Relation already exists!...\n";
        return;
    }else if(programSearch->firstPDR == NULL)
        programSearch->firstPDR = newNode;
    else
    {
        newNode -> next = programSearch->firstPDR;
        programSearch->firstPDR = newNode;
    }
    cout<<"\nRelation Insert Correctly!...\n";
}

void insertOfferProgramRelation(string offerID, string programID)
{
    struct offer * offerSearch = searchO(offerID);
    struct Program * programSearch = searchP(programID);

    if (offerSearch == NULL)
    {
        cout<<"\nThe Offer doesn't exist!...\n";
        return;
    }

    struct offerProgramRelation * newNode = new offerProgramRelation(programSearch);
    struct offerProgramRelation * localSearch = searchOPR(offerSearch, programSearch);

    if (localSearch != NULL)
    {
        cout<<"\nThis Relation already exists!...\n";
        return;
    }else if(offerSearch->firstOPR == NULL)
        offerSearch->firstOPR = newNode;
    else
    {
        newNode -> next = offerSearch->firstOPR;
        offerSearch->firstOPR = newNode;
    }
    cout<<"\nRelation Insert Correctly!...\n";
}

void insertUserCircuitRelation(string userID, string circuitID)
{
    struct user * userSearch = searchU(userID);
    struct circuit * circuitSearch = searchC(circuitID);

    if (userSearch == NULL)
    {
        cout<<"\nThe User doesn't exist!...\n";
        return;
    }

    struct userCircuitRelation * newNode = new userCircuitRelation(circuitSearch);
    struct userCircuitRelation * localSearch = searchUCR(userSearch, circuitSearch);

    if (localSearch != NULL)
    {
        cout<<"\nThis Relation already exists!...\n";
        return;
    }else if(userSearch->firstUCR == NULL)
        userSearch->firstUCR = newNode;
    else
    {
        newNode -> next = userSearch->firstUCR;
        userSearch->firstUCR = newNode;
    }
    cout<<"\nRelation Insert Correctly!...\n";
}

void insertCircuitProgramDestinyRelation(string circuitID, string programID, string destinyID)
{
    struct circuit * circuitSearch = searchC(circuitID);
    struct Program * programSearch = searchP(programID);
    struct Destiny * destinySearch = searchD(destinyID);

    if (circuitSearch == NULL)
    {
        cout<<"\nThe Circuit doesn't exist!...\n";
        return;
    }

    struct circuitProgramDestinyRelation * newNode = new circuitProgramDestinyRelation(destinySearch, programSearch);
    struct circuitProgramDestinyRelation * localSearch = searchCPDR(circuitSearch, programSearch, destinySearch);

    if (localSearch != NULL)
    {
        cout<<"\nThis Relation already exists!...\n";
        return;
    }else if(circuitSearch->firstCPDR == NULL)
        circuitSearch->firstCPDR = newNode;
    else
    {
        newNode -> next = circuitSearch->firstCPDR;
        circuitSearch->firstCPDR = newNode;
    }
    cout<<"\nRelation Insert Correctly!...\n";
}

void insertComent(string userID, string programID, string circuitID, string comment)
{
    struct user * userSearch = searchU(userID);
    struct Program * programSearch = searchP(programID);
    struct circuit * circuitSearch = searchC(circuitID);

    if (userSearch == NULL)
    {
        cout<<"\nThe User doesn't exist!...\n";
        return;
    }

    struct coment * newNode = new coment(programSearch, circuitSearch, comment);
    struct coment * localSearch = searchComment(userSearch, programSearch, circuitSearch, comment);

    if (localSearch != NULL)
    {
        cout<<"\nThis Relation already exists!...\n";
        return;
    }else if(userSearch->firstComent == NULL)
        userSearch->firstComent = newNode;
    else
    {
        newNode -> next = userSearch->firstComent;
        userSearch->firstComent = newNode;
    }
    cout<<"\nRelation Insert Correctly!...\n";
}

///---------------------- Final Insert Methods -------------------------///

///------------------------- Delete Methods ----------------------------///

void deleteProgramRelationInDestinies(string programID)
{
    struct Destiny * tempDestiny = firstDestiny;

    for(; tempDestiny != NULL; tempDestiny = tempDestiny -> next)
    {

        if (tempDestiny->firstDPR == NULL)
        {
            cout<<"\n\t There is nothing in the list relation!...\n"<<endl;
        }else
        {
            if ((tempDestiny->firstDPR->programRelation->id == programID) and (tempDestiny->firstDPR->next == NULL))
            {
                delete tempDestiny->firstDPR;
                tempDestiny->firstDPR = NULL;
            }else if (tempDestiny->firstDPR->programRelation->id == programID)
            {
                struct destinyProgramRelation * nodeToDelete = tempDestiny->firstDPR;
                tempDestiny->firstDPR = tempDestiny->firstDPR->next;
                delete nodeToDelete;
            }else
            {
                struct destinyProgramRelation * beforeNodeDPR = tempDestiny -> firstDPR;
                struct destinyProgramRelation * tempDPR = beforeNodeDPR->next;

                do
                {
                    if (tempDPR->programRelation->id == programID)
                    {
                        beforeNodeDPR -> next = tempDPR->next;
                        delete tempDPR;
                    }
                    tempDPR = tempDPR -> next;
                }while(tempDPR != NULL);
            }
            cout<<"\n\t Relation deleted...\n"<<endl;
        }
    }
}


void deleteProgram(string programID)
{
    if(firstProgram == NULL)
        cout<<"\n There is nothing in the list!...\n"<<endl;
    else if(firstProgram -> id == programID)
    {
        deleteProgramRelationInDestinies(programID);

        delete firstProgram;
        firstProgram = NULL;
        cout<<"\nProgram deleted correctly!...\n"<<endl;
    }else
    {   // The number is in the middle of the list or at the end.
        struct Program * beforeNode = firstProgram;
        struct Program * temp = firstProgram -> next;
        for (; temp != NULL; temp = temp -> next)
        {
            if (temp -> id == programID)
            {
                beforeNode -> next = temp -> next;
                deleteProgramRelationInDestinies(programID);
                delete temp;
                cout<<"\nProgram deleted correctly!...\n"<<endl;
                return;
            }else
                beforeNode = beforeNode -> next;
        }
        cout<<"\nNo number was found to delete."<<endl;
    }
}

///--------------------- Final Delete Methods --------------------------///

///-------------------------- Print Methods ----------------------------///

//Funcion para imprimir el destino
void printDestiny()
{
    struct Destiny * temp = firstDestiny;

    cout << "\n\t\tPrint all Destinies"<< endl;
    for (; temp != NULL; temp = temp -> next)
    {
        cout <<"\nId: "<< temp -> id << endl;
        cout <<"Name: "<< temp -> name << endl;
        cout <<"Detail: "<< temp -> detail << endl;

        if (temp->firstDPR == NULL)
            cout<<"\n\tThis destiny have not program relations!..."<<endl;
        else
        {
            cout <<"\n\tPrograms related with "<< temp -> name <<"."<<endl;
            struct destinyProgramRelation * tempRel = temp->firstDPR;
            for (; tempRel != NULL; tempRel = tempRel -> next)
            {
                cout <<"\t\tName: "<< tempRel->programRelation->name << endl;
            }
        }
    }
}

void printProgram()
{
    struct Program * temp = firstProgram;

    cout << "\n\t\tPrint all Programs"<< endl;
    for (;temp != NULL; temp = temp -> next)
    {
        cout <<"\nId: "<< temp -> id << endl;
        cout <<"Name: "<< temp -> name << endl;
        cout <<"Description: "<< temp -> description << endl;

        if (temp->firstPDR == NULL)
            cout<<"\n\tThis destiny have not destiny relations!..."<<endl;
        else
        {
            cout <<"\n\tDestinies related with "<< temp -> name <<"."<<endl;
            struct programDestinyRelation * tempRel = temp->firstPDR;
            for (; tempRel != NULL; tempRel = tempRel -> next)
            {
                cout <<"\t\tName: "<< tempRel->destinyRelation->name << endl;
            }
        }
    }
}

void printOffer()
{
    struct offer * temp = firstOffer;

    cout << "\n\t\tPrint all Offers"<< endl;
    do
    {
        cout <<"\nId: "<< temp -> id << endl;
        cout <<"Description: "<< temp -> description << endl;
        cout <<"Price: "<< temp -> price << endl;
        cout <<"Quantity: "<< temp -> quantity << endl;

        if (temp->firstOPR == NULL)
            cout<<"\n\tThis Offer have not program relations!..."<<endl;
        else
        {
            cout <<"\n\tPrograms related with "<< temp -> id <<"."<<endl;
            struct offerProgramRelation * tempRel = temp->firstOPR;
            for (; tempRel != NULL; tempRel = tempRel -> next)
            {
                cout <<"\t\tName: "<< tempRel->programRelation->name << endl;
            }
        }

        temp = temp -> next;
    }while(temp != firstOffer);
}

void printUser()
{
    struct user * temp = firstUser;

    cout << "\n\t\tPrint all Users"<< endl;
    for (;temp != NULL; temp = temp -> next)
    {
        cout <<"\nId: "<< temp -> id << endl;
        cout <<"Name: "<< temp -> name << endl;
        cout <<"LastName: "<< temp -> lastName << endl;

        if (temp->firstComent == NULL)
            cout<<"\n\tThis User have not Comment relations!..."<<endl;
        else
        {
            cout <<"\n\tComments related with "<< temp -> id<<"."<<endl;
            struct coment * tempRel = temp->firstComent;
            for (; tempRel != NULL; tempRel = tempRel -> next)
            {
                cout << "\t\tProgram:"<< tempRel->programRelation->name << ", Circuit: "<< tempRel->circuitRelation->name<<endl;
                cout <<"\t\tComment: "<< tempRel->comentDescription << endl;
            }
        }

        if (temp->firstUCR == NULL)
            cout<<"\n\tThis User have not Circuit relations!..."<<endl;
        else
        {
            cout <<"\n\tCircuits related with "<< temp -> id <<"."<<endl;
            struct userCircuitRelation * tempRel = temp->firstUCR;
            for (; tempRel != NULL; tempRel = tempRel -> next)
            {
                cout <<"\t\tName: "<< tempRel->circuitRelation->name << endl;
            }
        }
    }
}

void printCircuit()
{
    struct circuit * temp = firstCircuit;

    cout << "\n\t\tPrint all Circuits"<< endl;
    for (;temp != NULL; temp = temp -> next)
    {
        cout <<"\nId: "<< temp -> id << endl;
        cout <<"Name: "<< temp -> name << endl;

        if (temp->firstCPDR == NULL)
            cout<<"\n\tThis Circuit have not Program/Destiny relations!..."<<endl;
        else
        {
            cout <<"\n\Program & Destinies related with "<< temp -> name <<"."<<endl;
            struct circuitProgramDestinyRelation * tempRel = temp->firstCPDR;
            for (; tempRel != NULL; tempRel = tempRel -> next)
            {
                cout <<"\t\tProgram: "<< tempRel->programRelation->name <<" , Destiny: "<< tempRel->destinyRelation->name << endl;
            }
        }
    }
}

///----------------------- Final Print Methods ------------------------///

void loadData()
{
    //insertDestiny("123","Mexico", "asdasdasdasd");
    //insertDestiny("45","Japan", "asdasdasdasd");
    //insertDestiny("1231","Australia", "asdasdasdasd");
    //insertDestiny("1234","USA", "asdasdasdasd");

    //insertProgram("asd12313", "Calero", "asdadasdasda", 14.5);
    //insertProgram("asd12", "Cano", "asdadasdasda", 14.5);
    //insertProgram("asd123", "Barrio", "asdadasdasda",14.5);
    //insertProgram("asd1", "HolaMundo", "asdadasdasda", 14.5);

    //insertDestinyProgramRelation("123", "asd12313");
    //insertDestinyProgramRelation("123", "asd12");

    //insertProgramDestinyRelation("asd12", "123");
    //insertProgramDestinyRelation("asd12313", "123");

    insertOffer("1234", "asd", 15.6, 8);
    //insertOffer("123", "fgh", 15.6, 8);
    //insertOffer("12", "hjk", 15.6, 8);
    //insertOffer("134", "xcv", 15.6, 8);

    //insertUser("asd1","Andres", "Garcia");
    //insertUser("4324","Jose Carlos", "Rodriguez");
    //insertUser("asda","Jose Andres", "Salas");
    //insertUser("asd121","Andrea", "Garcia");
    //insertUser("ddfrr","Mainor", "Gamboa");

   // insertCircuit("asdasd", "Hola mundo");
    //insertCircuit("asdasfa", "Adios Mundo");
    //insertCircuit("2342fds", "Me cago en todo");
    //insertCircuit("yeyy34b4", "Puta mundo");

    //insertComent("asd1","asd12313", "asdasd", "Di pues la verdad es que la isla me parece horrible." );

    //printDestiny();
    //printProgram();
    printOffer();
    //printCircuit();
    //printUser();
}

//Funcion para insertar datos
void insertData(){
    cout << "              Insertar Datos" << endl;
    cout << endl;
    cout << "Lista de opciones: \n\n";
    cout << "1.Insertar Destino\n" << "2.Insertar Oferta\n" << "3.Insertar Programa\n";
    cout << "4.Insertar Circuito\n" << "5.Insertar Comentario de persona\n" <<  "6.Volver Atras\n\n";
    cout << endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    string option;
    cin >> option;
    if(option == "1"){
        system("cls");
        string id;
        string name;
        string detail;
        cout << "ID del Destino: ";
        cin >> id;
        cout << "Nombre del Destino: ";
        cin >> name;
        cout << "Detalle del Destino: ";
        cin >> detail;
        insertDestiny(id,name,detail);
    }
    else if(option == "2"){
        system("cls");
        string id;
        string description;
        double price;
        int quantity;
        cout << "ID de la Oferta: ";
        cin >> id;
        cout << "Descripcion  de la Oferta: ";
        cin >> description;
        cout << "Precio de la Oferta: ";
        cin >> price;
        cout << "Stock de la Oferta: ";
        cin >> quantity;
        insertOffer(id,description,price,quantity);
    }
    else if(option == "3"){
        system("cls");
        string id;
        string name;
        string description;
        double price;
        cout << "ID del programa: ";
        cin >> id;
        cout << "Nombre del programa: ";
        cin >> name;
        cout << "Descripcion del programa: ";
        cin >> description;
        cout << "Precio del programa: ";
        cin >> price;
        insertProgram(id,name,description,price);

    }
    else if(option == "4"){
        system("cls");
        string id;
        string name;
        cout << "ID del Circuito: ";
        cin >> id;
        cout << "Nombre del Circuito: ";
        cin >> name;
        insertCircuit(id,name);
    }
    else if(option == "5"){
        system("cls");
        string id;
        string name;
        string lastName;
        cout << "ID del Usuario: ";
        cin >> id;
        cout << "Nombre del Usuario: ";
        cin >> name;
        cout << "Apellido del Usuario: ";
        cin >> lastName;
        insertUser(id,name,lastName);
    }
    else if(option == "6"){
        system("cls");
        //maintenance();
    }
    else{
        system("cls");
        cout << option;
        cout << "\nOpcion no valida, por favor introduzca nuevamente la opcion deseada\n\n";
        return insertData();
    }


}

//Funcion para borrar datos
void deleteData(){
}
//Funcion para modificar precios de ofertas
void modifyOffer(){

}


//Funcion para modificar precios de circuitos
void modifyCircuit(){
}
//Funcion para modificar los precios
void modifyPrices(){
    cout << "              Modificar precios" << endl;
    cout << endl;
    cout << "Lista de opciones: \n\n";
    cout << "1.Modificar precios de ofertas\n" << "2.Modificar precios de Circuitos\n"  << "3.Volver atras\n\n";
    cout << endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    string option;
    cin >> option;
    if(option == "1"){
        system("cls");
        modifyOffer();
    }
    else if(option == "2"){
        system("cls");
        modifyCircuit();
    }
    else if(option == "3"){
        system("cls");
        //maintenance();
    }
    else{
        system("cls");
        cout << option;
        cout << "\nOpcion no valida, por favor introduzca nuevamente la opcion deseada\n\n";
        return modifyPrices();
    }


}

void menu();


//Menu de mantenimiento
void maintenance(){
    cout << "              Mantenimiento de Datos" << endl;
    cout << endl;
    cout << "Lista de opciones: \n\n";
    cout << "1.Insertar Datos\n" << "2.Borrar Datos\n" << "3.Modificar precios\n" << "4.Volver atras\n\n";
    cout << endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    string option;
    cin >> option;
    if(option == "1"){
        system("cls");
        insertData();
    }
    else if(option == "2"){
        system("cls");
        deleteData();
    }
    else if(option == "3"){
        system("cls");
        modifyPrices();
    }
    else if(option == "4"){
        system("cls");
        menu();
    }
    else{
        system("cls");
        cout << option;
        cout << "\nOpcion no valida, por favor introduzca nuevamente la opcion deseada\n\n";
        return maintenance();
    }
}

//Menu para las consultas
void consultation(){
}

//Funcion para imprimir programas de un destino
void proDestiny(){
}

//Funcion de las ofertas
void offers(){
}

//Funcion para imprimir los programas de una oferta
void programOffers(){
}

//Funcion para imprimir los circuitos
void circuits(){
}

//Funcion para retornar los circuitos que tiene un destino
void circuitDestiny(){
}

// menu de los reportes respectivos
void reports(){
    cout << "              Reportes Generales" << endl;
    cout << endl;
    cout << "Lista de opciones: \n\n";
    cout << "1.Ver lista de destinos disponibles\n" << "2.Ver programas de un destino\n" << "3.Ver lista de Ofertas disponibles\n";
    cout << "4.Ver programas de una oferta\n" << "5.Ver lista de Circuitos disponibles\n" <<"6.Lista de destinos de un circuito y su programa\n" << "7.Volver Atras\n\n";
    cout << endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    string option;
    cin >> option;
    if(option == "1"){
        system("cls");
        cout << "\nLista de Destinos disponibles:\n\n";
        printDestiny();
        cout << endl << endl;
        reports();
    }
    else if(option == "2"){
        system("cls");
        cout <<"\nProgramas de un destino X:\n\n";
        proDestiny();
        cout <<endl << endl;
        reports();
    }
    else if(option == "3"){
        system("cls");
        cout <<"\nOfertas disponibles:\n\n";
        offers();
        cout <<endl << endl;
        reports();
    }
    else if(option == "4"){
        system("cls");
        cout <<"\nProgramas de una oferta:\n\n";
        programOffers();
        cout <<endl << endl;
        reports();
    }
    else if(option == "5"){
        system("cls");
        cout <<"\nCircuitos disponibles:\n\n";
        circuits();
        cout <<endl << endl;
        reports();

    }
    else if(option == "6"){
        system("cls");
        cout <<"\nCircuitos de un destino:\n\n";
        circuitDestiny();
        cout <<endl << endl;
        reports();
    }
    else if(option == "7"){
        system("cls");
        menu();
    }
    else{
        system("cls");
        cout << option;
        cout << "\nOpcion no valida, por favor introduzca nuevamente la opcion deseada\n\n";
        return insertData();
    }


}

//Menu principal de la aplicacion
void menu(){
   cout << "              Bienvenido al sistema de la Agencia de Viajes Bananero" << endl;
    cout << endl;
    cout << "Lista de opciones: \n\n";
    cout << "1.Mantenimiento de Datos\n";
    cout << "2.Consultas\n";
    cout << "3.Reportes\n";
    cout << "4.Salir\n\n";
    cout << endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    string option;
    cin >> option;
    if(option == "1"){
        system("cls");
        maintenance();
    }
    else if(option == "2"){
        system("cls");
        consultation();
    }
    else if(option == "3"){
        system("cls");
        reports();
        return;
    }
    else if(option == "4"){
        system("cls");
        return;
    }
    else{
        system("cls");
        cout << option;
        cout << "\nOpcion no valida, por favor introduzca nuevamente la opcion deseada\n\n";
        return menu();
    }

}

int main()
{
    //loadData();
    //modifyPrices();

    //deleteProgram("asd12");


    menu();
    return 0;
}
