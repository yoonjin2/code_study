import "math"
var answer int64 = 0;
func dfs(edges [][]int, sum []int, now int, parent int) []int {
    for i := 0 ; i < len(edges[now]) ; i++ {
        if edges[now][i] != parent {
            sum=dfs(edges, sum, edges[now][i], now)
        }
    }
    sum[parent]+=sum[now]
    answer+=int64(math.Abs(float64(sum[now])))
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
    }
    return -1
}
