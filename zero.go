import "math"
var answer int64 = 0;
//parent는 부모노드 , now는 현재노드
func dfs(edges [][]int, sum []int, now int, parent int) []int {
    for i := 0 ; i < len(edges[now]) ; i++ {
        if edges[now][i] != parent {
            sum=dfs(edges, sum, edges[now][i], now)
        } // 부모 노드가 아닐 경우에만 거르면 된다
    }
    sum[parent]+=sum[now] // 자식노드+=부모노드를 해서 부모노드에 가중치를 몰아넣음
    answer+=int64(math.Abs(float64(sum[now]))) //1씩 더하거나 뺀 횟수
    return sum
}
func solution(a []int, edges [][]int) int64 {
    sum:=make([]int, len(a))
    for i := 0 ; i < len(a); i++ {
        sum[i]=a[i]
    }
    graph:=make([][]int, len(a))
    for i := 0 ; i < len(edges); i++ {
        graph[edges[i][0]]=append(graph[edges[i][0]], edges[i][1])
        graph[edges[i][1]]=append(graph[edges[i][1]], edges[i][0])
    }
    sum=dfs(graph,sum,0,0)
    if(sum[0]==0) {
        return answer
    } //루트 가중치가 0인 경우에 answer를 리턴
    return -1 // 그렇지 않으면 -1을 리턴
}
