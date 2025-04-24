#include <iostream>
using namespace std;

class SparseMatrix {
private:
    struct Node {
        int row;
        int col;
        int val;
        Node* next;
    };

    Node* head;

public:
    SparseMatrix() {
        head = nullptr;
    }

    void insert(int r, int c, int value) {
        if (value == 0) return;

        Node* newNode = new Node{r, c, value, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        cout << "Row Col Val\n";
        while (temp != nullptr) {
            cout << temp->row << "   " << temp->col << "   " << temp->val << endl;
            temp = temp->next;
        }
    }
};


int main() {
    SparseMatrix sm;
    int matrix[4][5] = {
        {0, 0, 0, 5, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 0, 7},
        {2, 0, 0, 0, 0}
    };

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            sm.insert(i, j, matrix[i][j]);

    sm.display();
    return 0;
}
