# 정답!
# https://programmers.co.kr/learn/courses/30/lessons/42578?language=python3

# 2021.05.27 / 정승균
# 프로그래머스 - 위장




# 해시함수
def createHashCode( size, value ):
	return (len(value) + int(ord( value[0] )) + int(ord( value[-1] ))) % size
# 해시테이블에서 value값 찾기
def serchHash( hashTable, hashCode, value ):
	# 해당 해시코드 위치가 비어있지 않다면
	if hashTable[ hashCode ] != None:
		# 해당 해시코드의 노드 중에서 value와 일치하는 값 찾기
		for node in hashTable[ hashCode ]:
			if node[0] == value:
				# 일치하는 노드 반환
				return node


def solution( clothes ):
	# 존재하는 옷의 종류
	types = []
	# 종류별로 개수를 체크하기 위한 해시테이블
	hashTable = []

	# 해시테이블 초기화
	for i in range( len(clothes) ):
		hashTable.append( None )

	# 연결리스트에 값 삽입
	for cloth in clothes:
		# cloth의 종류로 해시코드를 생성
		hashCode = createHashCode( len(hashTable), cloth[1] )
		node = serchHash( hashTable, hashCode, cloth[1] )
		# cloth[1]값이 해시테이블에 존재하지 않거나
		if node == None:
			# 해시코드 위치가 비어있다면
			if hashTable[ hashCode ] == None:
				# 해시코드 위치에 새 노드를 생성
				hashTable[ hashCode ] = []
			hashTable[ hashCode ].append( [cloth[1], 1] )
			# types리스트에 옷의 종류 요소 추가
			types.append( cloth[1] )
		# cloth[1]값이 해시테이블에 존재한다면
		else:
			# 해당 옷의 개수 증가
			node[1] += 1


	# 경우의 수 계산
	answer = 1
	for i in range( len(types) ):
		hashCode = createHashCode( len(hashTable), types[i] )
		node = serchHash( hashTable, hashCode, types[i] )
		answer = answer * (node[1] + 1)

	answer -= 1
	return answer




clothes = [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"], ["redhat", "headgear"], ["Niky", "shuse"]]
print( solution( clothes ) )