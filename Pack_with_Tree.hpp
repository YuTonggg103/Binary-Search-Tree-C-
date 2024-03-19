#include <iostream>
#include <string>
#include <iomanip> // for setw
#include <fstream> // for file
#include <sstream>
using namespace std;

struct treeNode {
    string trackNum;
    int date;
    string senderName;
    string senderPhoneNo;
    string receiverName;
    string receiverPhoneNo;
    int postcode;
    string province;
    string state;
    string country;
    double shippingWeight;
    double shippingFee;
    treeNode* parent;
    treeNode* left;
    treeNode* right;

    treeNode(string trackNum, int date, string senderName, string senderPhoneNo,
        string receiverName, string receiverPhoneNo, int postcode, string province,
        string state, string country, double shippingWeight, double shippingFee) {
        this->trackNum = trackNum;
        this->date = date;
        this->senderName = senderName;
        this->senderPhoneNo = senderPhoneNo;
        this->receiverName = receiverName;
        this->receiverPhoneNo = receiverPhoneNo;
        this->postcode = postcode;
        this->province = province;
        this->state = state;
        this->country = country;
        this->shippingWeight = shippingWeight;
        this->shippingFee = shippingFee;

        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class StateBasedTree {
    treeNode* root;
    string treeName;

public:
    StateBasedTree(string treeName) {
        root = nullptr;
        this->treeName = treeName;
    }
    ~StateBasedTree()
    {
        cout << treeName << " is currently removed from the memory now!" << endl;
    }

    void addNode(string trackNum, int date, string senderName, string senderPhoneNo,
        string receiverName, string receiverPhoneNo, int postcode, string province,
        string state, string country, double shippingWeight, double shippingFee) {
        static int parcelNumber = 1;
        cout << endl << string(230, '-') << endl;
        cout << "Parcel " << parcelNumber << " information" << endl;
        parcelNumber++;
        cout << string(230, '-') << endl;

        string choice;
        cout << left << setw(20) << "Tracking Number" << setw(20) << "Order Date" << setw(20) << "Sender Name" << setw(20) << "Sender Phone No" << setw(20) << "Receiver Name"
            << setw(20) << "Receiver Phone No" << setw(20) << "Delivery Postcode" << setw(20) << "Delivery Province" << setw(20) << "Delivery State" << setw(20)
            << "Delivery Country" << setw(20) << "Parcel Weight (KG)" << setw(20) << "Shipping Fee" << endl;
        cout << left << setw(20) << trackNum << setw(20) << date << setw(20) << senderName << setw(20) << senderPhoneNo << setw(20) << receiverName << setw(20)
            << receiverPhoneNo << setw(20) << postcode << setw(20) << province << setw(20) << state << setw(20) << country << setw(20) << shippingWeight << setw(20)
            << shippingFee;
        cout << endl << string(230, '-') << endl;

        while (true) {
            cout << endl << "Do you want to UPDATE (delivery address) (1.YES 2.NO):";
            cin >> choice;
            if (choice == "1") {
                string updateChoice;
                bool loop = true;
                while (loop) {
                    cout << "\nWhich information you want to update? " << endl;
                    cout << "1.Delivery Postcode    2.Delivery Province    3.Delivery State    4.Delivery Country\nEnter a Number: ";
                    cin >> updateChoice;
                    if (updateChoice == "1") {
                        int newPostcode;
                        cout << "Enter a New Delivery Postcode: ";
                        cin >> newPostcode;
                        postcode = newPostcode;
                    }
                    else if (updateChoice == "2") {
                        string newProvince;
                        cout << "Enter a New Delivery Province: ";
                        cin.ignore();
                        getline(cin, newProvince);
                        province = newProvince;
                    }
                    else if (updateChoice == "3") {
                        string newStates;
                        cout << "Enter a New Delivery States: ";
                        cin.ignore();
                        getline(cin, newStates);
                        state = newStates;
                    }
                    else if (updateChoice == "4") {
                        string newCountry;
                        cout << "Enter a New Delivery Country: ";
                        cin.ignore();
                        getline(cin, newCountry);
                        country = newCountry;
                    }
                    else {
                        cout << "\nInvalid Input\n";
                        continue;
                    }

                    string continueChoice;
                    while (true) {
                        cout << "\nDo you want continue update Parcel Address Information ? (1.YES  2.NO): ";
                        cin >> continueChoice;
                        if (continueChoice == "1") {
                            break;
                        }
                        else if (continueChoice == "2") {
                            cout << "\nSystem Start Classified " << trackNum << " this Parcel.\n" << endl;
                            treeNode* newNode = new treeNode(trackNum, date, senderName, senderPhoneNo, receiverName,
                                receiverPhoneNo, postcode, province, state, country, shippingWeight, shippingFee);
                            if (root == nullptr) {
                                root = newNode;
                            }
                            else {
                                insertNodeToTree(root, newNode);
                            }
                            cout << endl;
                            loop = false;
                            break;
                        }


                        else {
                            cout << "\nInvalid Input\n";
                        }
                    }
                }
            }
            else if (choice == "2") {
                cout << "\nSystem Start Classified " << trackNum << " this Parcel.\n" << endl;
                treeNode* newNode = new treeNode(trackNum, date, senderName, senderPhoneNo, receiverName, receiverPhoneNo, postcode, province, state, country, shippingWeight, shippingFee);
                if (root == nullptr) {
                    root = newNode;
                }
                else {
                    insertNodeToTree(root, newNode);
                }
                break;
            }
            else {
                cout << "Invalid Input" << endl;
                continue;
            }
            break;
        }
    }

    void insertNodeToTree(treeNode* root, treeNode* newNode) {
        if (newNode->country < root->country) {
            if (root->left == nullptr) {// if smaller than root node insert to the left subtree
                root->left = newNode;
                newNode->parent = root;
            }
            else
                insertNodeToTree(root->left, newNode);
        }
        else if (newNode->country > root->country) {
            if (root->right == nullptr) { // if bigger than root node insert to the right subtree
                root->right = newNode;
                newNode->parent = root;
            }
            else
                insertNodeToTree(root->right, newNode);
        }
        else { // if countries are equal, compare states
            if (newNode->state < root->state) {
                if (root->left == nullptr) {
                    root->left = newNode;
                    newNode->parent = root;
                    cout << "Parent node:" << root->trackNum << "  left(<) NewNode: " << newNode->trackNum << endl;
                }
                else
                    insertNodeToTree(root->left, newNode);
            }
            else if (newNode->state > root->state) {
                if (root->right == nullptr) {
                    root->right = newNode;
                    newNode->parent = root;
                    cout << "Parent node:" << root->trackNum << "  right(>) NewNode: " << newNode->trackNum << endl;
                }
                else
                    insertNodeToTree(root->right, newNode);
            }
            else { // If states are equal, compare province
                if (newNode->province < root->province) {
                    if (root->left == nullptr) {
                        root->left = newNode;
                        newNode->parent = root;
                        cout << "Parent node:" << root->trackNum << "  left(<) NewNode: " << newNode->trackNum << endl;
                    }
                    else
                        insertNodeToTree(root->left, newNode);
                }
                else if (newNode->province > root->province) {
                    if (root->right == nullptr) {
                        root->right = newNode;
                        newNode->parent = root;
                        cout << "Parent node:" << root->trackNum << "  right(>) NewNode: " << newNode->trackNum << endl;
                    }
                    else
                        insertNodeToTree(root->right, newNode);
                }
                else {// If province are equal, compare postcodes
                    if (newNode->postcode < root->postcode) {
                        if (root->left == nullptr) {
                            root->left = newNode;
                            newNode->parent = root;
                            cout << "Parent node:" << root->trackNum << "  left(<) NewNode: " << newNode->trackNum << endl;
                        }
                        else
                            insertNodeToTree(root->left, newNode);
                    }
                    else if (newNode->postcode > root->postcode) {
                        if (root->right == nullptr) {
                            root->right = newNode;
                            newNode->parent = root;
                            cout << "Parent node:" << root->trackNum << "  right(>) NewNode: " << newNode->trackNum << endl;
                        }
                        else
                            insertNodeToTree(root->right, newNode);
                    }
                    else { // If postcodes are equal, compare tracking numbers
                        if (newNode->trackNum < root->trackNum) {
                            if (root->left == nullptr) {
                                root->left = newNode;
                                newNode->parent = root;
                                cout << "Parent node:" << root->trackNum << "  left(<) NewNode: " << newNode->trackNum << endl;
                            }
                            else
                                insertNodeToTree(root->left, newNode);
                        }
                        else if (newNode->trackNum > root->trackNum) {
                            if (root->right == nullptr) {
                                root->right = newNode;
                                newNode->parent = root;
                                cout << "Parent node:" << root->trackNum << "  right(>) NewNode: " << newNode->trackNum << endl;
                            }
                            else
                                insertNodeToTree(root->right, newNode);
                        }// all tracking number is unique, no equal trackNumber are equal
                    }
                }
            }
        }
    }

    void askToDelete() {
        string askDelete;
        string trackNumDelete;
        cout << endl << string(150, '-') << endl;
        bool loop = true;
        while (loop) {
            cout << "Do you want to delete any parcel information? : (1.YES 2.NO): ";
            cin >> askDelete;
            while (loop) {
                if (askDelete == "1") {
                    cout << "Enter Tracking Number that you want to delete: ";
                    cin >> trackNumDelete;
                    readFile(trackNumDelete);
                }
                else if (askDelete == "2") {
                    if (remove("AllParcelInformation.txt") != 0) { // remove file
                        cout << "Error deleting file." << endl;
                    }
                    else {
                        cout << "File deleted successfully." << endl;
                    }return;
                }
                else {
                    cout << "Invalid Input" << endl;
                    break;
                }
                string continueDelete;
                while (true) {
                    cout << "Do you want to continue delete? (1.YES 2. NO): ";
                    cin >> continueDelete;
                    if (continueDelete == "1") {
                        break;
                    }
                    else if (continueDelete == "2") {
                        if (remove("AllParcelInformation.txt") != 0) {// remove file
                            cerr << "Error deleting file." << endl;
                        }
                        else
                            cout << "File deleted successfully." << endl;
                        loop = false;
                        break;
                    }
                    else {
                        cout << "\nInvalid Input. Enter Again." << endl;
                        continue;
                    }
                }
            }
        }
    }

    void readFile(string trackNumDelete) {
        string trackNum;
        string date;
        string senderName;
        string senderPhoneNo;
        string receiverName;
        string receiverPhoneNo;
        string postcode;
        string province;
        string state;
        string country;
        string shippingWeight;
        string shippingFee;
        string line;
        bool noInfile = true;
        ifstream readFile("AllParcelInformation.txt");

        if (!readFile.is_open()) {
            cout << "Could not open the file." << endl;
            return;
        }
        while (getline(readFile, line)) {
            stringstream lineStream(line);
            //use a stringstream to tokenize the line based on a comma
            getline(lineStream, trackNum, ',');
            getline(lineStream, date, ',');
            getline(lineStream, senderName, ',');
            getline(lineStream, senderPhoneNo, ',');
            getline(lineStream, receiverName, ',');
            getline(lineStream, receiverPhoneNo, ',');
            getline(lineStream, postcode, ',');
            getline(lineStream, province, ',');
            getline(lineStream, state, ',');
            getline(lineStream, country, ',');
            getline(lineStream, shippingWeight, ',');
            getline(lineStream, shippingFee, ',');
            if (trackNum == trackNumDelete) {
                deleteNode(trackNum, date, senderName, senderPhoneNo, receiverName, receiverPhoneNo, postcode, province, state, country, shippingWeight, shippingFee);
                noInfile = false;
                break;
            }
        }if (noInfile) {
            cout << "This node don't in tree." << endl;
        }readFile.close();
    }

    void deleteNode(string deletedtrackNum, string date, string senderName, string senderPhoneNo, string receiverName, string receiverPhoneNo, string postcode, string province,
        string state, string country, string shippingWeight, string shippingFee) {
        if (root == nullptr) { //tree is empty 
            cout << "Tree already empty! No deletion here!" << endl;
            return;
        }
        treeNode* parent = nullptr;  //tree is not empty then start find the delete node location
        treeNode* current = root;
        while (current->trackNum != deletedtrackNum) {
            parent = current;
            if (country > current->country)
                current = current->right;
            else if (country < current->country)
                current = current->left;
            else {  //same country, compare with state
                if (state > current->state)
                    current = current->right;
                else if (state < current->state)
                    current = current->left;
                else { //same state, compare with province
                    if (province > current->province)
                        current = current->right;
                    else if (province < current->province)
                        current = current->left;
                    else { //same province, compare with postcode
                        int intPostcode = stoi(postcode);
                        if (intPostcode < current->postcode)
                            current = current->left;
                        else if (intPostcode > current->postcode)
                            current = current->right;
                        else { //same postcode, compare with tracking number
                            if (deletedtrackNum > current->trackNum)
                                current = current->right;
                            else if (deletedtrackNum < current->trackNum)
                                current = current->left;
                        }
                    }
                }
            }
            if (current == nullptr) {
                cout << "\nTRACKING NUMBER: " << deletedtrackNum << " cannot find this node in tree, Please search reenter again." << endl;
                return;
            }
        }//succesfull found node  
        if (current->left == nullptr && current->right == nullptr) { //node is a leaf node, direct delete
            if (parent == nullptr) //tree only have one node(root)
                root = nullptr;
            else if (parent->left == current) //node be deleted is under the root left side
                parent->left = nullptr;
            else
                parent->right = nullptr; //node be deleted is under the root right side
            delete current;
        }
        else if (current->left != nullptr && current->right == nullptr) { //node have left subtree but dont have right subtree (replace with 1st current->left  node)
            if (parent == nullptr) //node is root node and have left subtree, change root to 1st current->left node
                root = current->left;
            else if (parent->left == current) //node be deleted is under the parent left side
                parent->left = current->left;
            else
                parent->right = current->left; //node be deleted is under the parent right side
            delete current;
        }
        else if (current->left == nullptr && current->right != nullptr) { //node have left subtree but dont have left subtree (replace with 1st current->right  node)
            if (parent == nullptr)//node is root node and have right subtree, change root to 1st current->right node
                root = current->right;
            else if (parent->left == current)
                parent->left = current->right;
            else
                parent->right = current->right;
            delete current;
        }
        else if (current->left != nullptr && current->right != nullptr) { //node have left and right subtree, replace with max value from node->left subtree
            treeNode* replace = current->left;
            treeNode* subparent = nullptr;
            while (replace->right != NULL) {  //find the max value // until replace node dont have right node
                subparent = replace;
                replace = replace->right;
            }
            current->trackNum = replace->trackNum; current->date = replace->date; current->senderName = replace->senderName;
            current->senderPhoneNo = replace->senderPhoneNo; current->receiverName = replace->receiverName; current->receiverPhoneNo = replace->receiverPhoneNo;
            current->postcode = replace->postcode; current->province = replace->province; current->state = replace->state;
            current->country = replace->country; current->shippingWeight = replace->shippingWeight; current->shippingFee = replace->shippingFee;
            if (subparent == NULL)// replace parent node is current node and replace node dont have right nodes
                current->left = replace->left;  // replace node is leaf node
            else // replace parent node != current node
                subparent->right = replace->left;
            delete replace;
        }
    }

    void inorderOutputByState(int num) {
        if (num == 1) { //before delete
            cout << "\nIn-order Output by State:" << endl;
            cout << endl << string(230, '-') << endl;
            cout << setw(20) << "Tracking Number" << setw(20) << "Order Date" << setw(20) << "Sender Name" << setw(20) << "Sender Phone No" << setw(20) << "Receiver Name"
                << setw(20) << "Receiver Phone No" << setw(20) << "Delivery Postcode" << setw(20) << "Delivery Province" << setw(20) << "Delivery State" << setw(20)
                << "Delivery Country" << setw(20) << "Parcel Weight (KG)" << setw(20) << "Shipping Fee";
            cout << endl << string(230, '-') << endl;
            inorderOutputByState(root, num);
        }
        else if (num == 2) { //after delete
            cout << "\nIn-order Output by State:" << endl;
            cout << endl << string(230, '-') << endl;
            cout << setw(20) << "Tracking Number" << setw(20) << "Order Date" << setw(20) << "Sender Name" << setw(20) << "Sender Phone No" << setw(20) << "Receiver Name"
                << setw(20) << "Receiver Phone No" << setw(20) << "Delivery Postcode" << setw(20) << "Delivery Province" << setw(20) << "Delivery State" << setw(20)
                << "Delivery Country" << setw(20) << "Parcel Weight (KG)" << setw(20) << "Shipping Fee";
            cout << endl << string(230, '-') << endl;
            inorderOutputByState(root, num);
        }
    }

    void writeToFile(string trackNum, int date, string senderName, string senderPhoneNo, string receiverName, string receiverPhoneNo, int postcode, string province,
        string state, string country, double shippingWeight, double shippingFee) {
        string fileName = "AllParcelInformation.txt";
        ofstream MyFile;
        MyFile.open(fileName, ios::app);// Open the file in append mode
        if (MyFile.is_open()) { // Check if the file is successfully opened  // append to the file
            MyFile << trackNum << "," << date << "," << senderName << "," << senderPhoneNo << "," << receiverName << "," << receiverPhoneNo << "," << postcode << "," << province << ","
                << state << "," << country << "," << shippingWeight << "," << shippingFee << endl;
            MyFile.close();
            cout << "Data appended to file: " << fileName << endl << endl;
        }
        else
            cout << "Error opening file: " << fileName << endl;
    }

    void writeToStateFile(string trackNum, int date, string senderName, string senderPhoneNo, string receiverName, string receiverPhoneNo, int postcode, string province,
        string state, string country, double shippingWeight, double shippingFee) {
        string fileName = state + ".txt";
        ofstream MyFile;
        MyFile.open(fileName, ios::app);// Open the file in append mode
        if (MyFile.is_open()) {// Check if the file is successfully opened  // append to the file
            MyFile << trackNum << "," << date << "," << senderName << "," << senderPhoneNo << "," << receiverName << "," << receiverPhoneNo << "," << postcode << "," << province << ","
                << state << "," << country << "," << shippingWeight << "," << shippingFee << endl;
            MyFile.close();
            cout << "Data appended to file: " << fileName << endl << endl;
        }
        else
            cout << "Error opening file: " << fileName << endl;
    }

private:
    void inorderOutputByState(treeNode* root, int num) {
        if (root != nullptr) {
            inorderOutputByState(root->left, num);
            outputNode(root, num);
            inorderOutputByState(root->right, num);
        }
    }

    void outputNode(treeNode* node, int num) {

        cout << left << setw(20) << node->trackNum << setw(20) << node->date << setw(20) << node->senderName << setw(20) << node->senderPhoneNo
            << setw(20) << node->receiverName << setw(20) << node->receiverPhoneNo << setw(20) << node->postcode << setw(20) << node->province << setw(20) << node->state
            << setw(20) << node->country << setw(20) << node->shippingWeight << setw(20) << node->shippingFee << endl;

        if (num == 1) {
            writeToFile(node->trackNum, node->date, node->senderName, node->senderPhoneNo, node->receiverName,
                node->receiverPhoneNo, node->postcode, node->province, node->state, node->country, node->shippingWeight,
                node->shippingFee);
        }if (num == 2) {
            writeToStateFile(node->trackNum, node->date, node->senderName, node->senderPhoneNo, node->receiverName,
                node->receiverPhoneNo, node->postcode, node->province, node->state, node->country, node->shippingWeight,
                node->shippingFee);
        }
    }
};