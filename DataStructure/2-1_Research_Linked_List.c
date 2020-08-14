// 일부 출처: 한빛아카데미 'C로 배우는 쉬운 자료구조'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode1 {
    // 데이터가 들어갈 공간
    char data[100];
    // head가 들어갈 구조체
    struct ListNode1* link;
// 구조체 별칭을 listNode로 선언
} listNode1;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
    // listNode의 메모리 주소를 가르킬 수 있는 head
    listNode1* head;
// 구조체 별칭을 linkedList_h로 선언
} linkedList_h1;

// 공백 연결 리스트를 생성하는 함수
linkedList_h1* createLinkedList_h1(void) {
    // linkedList_h 포인터 L 선언
    linkedList_h1* L;
    // linkedList_h의 사이즈 만큼의 메모리를 L에 할당
    L = (linkedList_h1*)malloc(sizeof(linkedList_h1));
    // 다음 링크의 포인터는 NULL로 정의
    L -> head = NULL;
    // L을 리턴. -> data 부분에 데이터를 넣지 않았고, head를 NULL로 지정했으므로, 공백 연결 리스트를 만든 것이 됨.
    return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h1(linkedList_h1* L) {
    // 임시적으로 저장할 변수 정의
    listNode1* p;
    // 이어지는 link가 끝이 날때까지 반복
    while(L -> head != NULL) {
        // 임시로 정의한 p에 head 포인터를 가르킴
        p = L -> head;
        // L의 다음 노드의 메모리 주소를 다음다음의 메모리 주소로 지정 (한칸 당기기)
        L -> head = L -> head -> link;
        // 메모리 할당을 취소
        free(p);
        // p를 NULL 값으로 설정
        p = NULL;
    } // while END
}

// 연결 리스트를 순서대로 출력하는 연산
void printList1(linkedList_h1* L) {
    // 임시 구조체 포인터 p
    listNode1* p;
    // 출력 시작
    printf("L = (");
    // p를 입력 받은 노드의 다음 노드를 가르키게 만듬.
    p = L -> head;
    
    // p가 NULL이 될때까지
    while(p != NULL) {
        // 현재 p의 데이터를 출력
        printf("%s", p -> data);
        // p에 다음 노드를 가르키게 만듬.
        p = p -> link;
        // 다음 노드가 존재할 경우
        if(p != NULL) {
            // ", "를 출력
            printf(", ");
        } // if END
    } // while END
    
    // 출력 종료
    printf(")\n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode1(linkedList_h1 *L, char *x) {
    // 새로운 노드의 데이터를 저장할 포인터
    listNode1* newNode;
    // 새로운 노드에 메모리 할당
    newNode = (listNode1*)malloc(sizeof(listNode1));
    // 새로운 노드의 데이터 부분에 입력 받은 데이터를 넣음.
    strcpy(newNode -> data, x);
    // 첫번째 노드에 삽입하는 것이므로 다음 노드의 링크를 현재의 첫번째 노드로 함.
    newNode -> link = L -> head;
    // 현재 첫번째 노드의 링크를 새로운 노드의 링크로 대체
    L -> head = newNode;
}

// 마지막 노드로 삽입하는 연산
void insertLastNode1(linkedList_h1* L, char* x) {
    // 새로운 노드를 저장할 포인터
    listNode1* newNode;
    // 임시적으로 저장할 포인터
    listNode1* temp;
    // 새로운 노드의 메모리를 할당함
    newNode = (listNode1*)malloc(sizeof(listNode1));
    // 새로운 노드의 데이터 부분에 입력받은 데이터를 넣음.
    strcpy(newNode -> data, x);
    // 마지막에 넣는 것이니 link 부분은 NULL로 설정
    newNode -> link = NULL;
    
    // 현재 리스트가 공백인 경우
    if (L -> head == NULL) {
        L -> head = newNode; // 새 노드를 리스트의 시작 노드로 연결
        return;
    }
    
    // 현재 리스트가 공백이 아닌 경우
    temp = L -> head;
    while(temp -> link != NULL) {
        temp = temp -> link;
    }
    temp -> link = newNode;
    
}


// 다음 노드의 주소를 표시하는 함수
void printNextAddress(linkedList_h1* L) {
    // 임시적으로 저장할 포인터
    listNode1* temp;
    // 첫번째 노드를 temp에 저장
    temp = L -> head;
    
    // 다음 노드가 없을 때까지 반복
    while(temp -> link != NULL) {
        // 다음 노드의 주소 출력
        printf("현재 노드의 주소: 0x%p\n", temp);
        printf("다음 노드의 주소: 0x%p\n", temp -> link);
        // temp의 데이터를 다음 노드로 변경
        temp = temp -> link;
    }
    
    printf("현재 노드의 주소: 0x%p\n", temp);

}

// 메인 함수
int research_linked_list() {
    linkedList_h1* L;
    L = createLinkedList_h1();
    insertFirstNode1(L, "수");
    insertLastNode1(L, "금");
    insertFirstNode1(L, "월");
    printList1(L);
    printf("첫번째 노드 주소: 0x%p\n", L -> head);
    printNextAddress(L);
    
    return 0;
}
