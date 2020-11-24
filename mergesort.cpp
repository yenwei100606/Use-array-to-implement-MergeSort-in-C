// C++ code
#include <iostream>
#include <vector>

const int Max = 1000;

void Merge(std::vector<int> &Array, int front, int mid, int end){

    // �Q�� std::vector ��constructor, 
    // ��array[front]~array[mid]��i LeftSub[]
    // ��array[mid+1]~array[end]��i RightSub[]
    std::vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                     RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(), Max);      // �bLeftSub[]���ݥ[�J�Ȭ� Max ������
    RightSub.insert(RightSub.end(), Max);    // �bRightSub[]���ݥ[�J�Ȭ� Max ������

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(std::vector<int> &array, int front, int end){
                                         // front�Pend���x�}�d��
    if (front < end) {                   // ��ܥثe���x�}�d��O���Ī�
        int mid = (front+end)/2;         // mid�Y�O�N�x�}��b����index
        MergeSort(array, front, mid);    // �~��divide�x�}���e�b�qsubarray
        MergeSort(array, mid+1, end);    // �~��divide�x�}����b�qsubarray
        Merge(array, front, mid, end);   // �N���subarray�����, �æX�֥X�Ƨǫ᪺�x�}
    }
}

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int arr[] = {5,3,8,6,2,7,1,4};
    std::vector<int> array(arr, arr+sizeof(arr)/sizeof(int));

    std::cout << "original:\n";
    PrintArray(array);

    MergeSort(array, 0, 7);
    std::cout << "sorted:\n";
    PrintArray(array);

    return 0;
}
