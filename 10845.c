#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// 노드 
typedef struct node {
    int key;
    struct node * prev , * next;
} node;
// 큐
typedef struct queue {
    node * front , * rear;
    int size;
} queue;
// 큐의 front와 rear에 동적할당 후 노드를 연결시킴
void init_queue( queue * que ) {
    que -> front = ( node * ) malloc ( sizeof ( node ) );
    que -> rear = ( node * ) malloc (sizeof ( node ) );
    que -> front -> next = que -> rear;
    que -> front -> prev = que -> front;
    que -> rear -> next = que -> rear;
    que -> rear -> prev = que -> front;
    que -> size = 0;
}
// 값 푸시
void push ( queue * que , int item) {
    node * q;
    if ( ( q = ( node * ) malloc ( sizeof ( node ) ) ) == NULL ) {
        return ;
    }
    else {
        q -> key = item;
        que -> rear -> prev -> next = q;
        q -> prev = que -> rear -> prev ;
        que -> rear -> prev = q;
        q -> next = que -> rear;
    }
    que -> size ++;
}
// 값 팝
void pop ( queue * que ) {
    if ( que -> size == 0 ) {
        puts ( "-1" );
        return ;
    }
    else {
        node *q = que -> front -> next;
        que -> front -> next = que -> front -> next -> next;
        que -> front -> next -> prev = que -> front;
        printf( "%d\n" , q -> key );
        free( q );
        que -> size --;
    }
}
// 비었는지 확인 
void empty ( queue * que ) {
    if ( que -> size == 0 ) {
        puts( "1" );
        return;
    }
    puts( "0" ) ;
}
// 큐의 사이즈
void size ( queue * que ) {
    printf( "%d\n" , que -> size );
}
//큐의 맨 앞쪽 숫자
void front ( queue * que ) {
    if ( que -> size == 0 ) {
        puts( "-1" );
        return;
    }
    printf( "%d\n" , que -> front -> next -> key );
}
// 큐의 맨 뒤쪽 숫자
void back ( queue * que ) {
    if ( que -> size == 0) {
        puts( "-1" );
        return;
    }
    printf("%d\n", que -> rear -> prev -> key );
}
//명령을 해석하고 실행
void task ( queue * que) {
    char command[6]={'\0', };
        scanf( "%s" , command );
    if ( strcmp ( command , "pop" ) == 0 ) {
        pop( que );
    } else if ( strcmp ( command , "size" ) == 0 ) {
        size( que );
    } else if ( strcmp ( command, "empty" ) == 0 ) {
        empty ( que );
    } else if ( strcmp ( command, "back" ) == 0 ) {
        back ( que );
    } else if ( strcmp ( command, "front" ) == 0 ) {
        front ( que );
    } else if ( strcmp ( command , "push" ) == 0 ) {
        auto int item;
        scanf( "%d" , &item );
        push ( que , item );
    } else return ;
}
//큐를 비우고 완전히 동적할당 해제
void free_queue ( queue * que ) {
    node * q = que -> front -> next ;
    while ( q -> next != que -> rear) {
        free ( q );
        q= q -> next;
    }
    que -> size = 0;
    free( que -> front );
    free( que -> rear );
}
// 메인 함수 
int main ( void ) {
    queue que ;
    init_queue ( &que );
    //큐 생성 완료
    int i, N;
    scanf ( "%d" , &N );
    // 명령의 횟수
    for ( i = 0 ; i < N ; i ++ ) {
        task ( & que );
    } //에 알맞게 반복문을 돌림
    free_queue ( & que );
    return 0;
}
