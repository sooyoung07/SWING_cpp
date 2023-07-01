name = input("이름 입력 : ")
num = int(input("학번 입력 : "))
kor = int(input("국어점수 입력 : "))
math = int(input("수학점수 입력 : "))
eng = int(input("영어점수 입력 : "))

avg = (kor + math + eng) / 3

print("\n이름 : %s" % name)
print("학번 : %d" % num)
print("국어점수 : %d" % kor)
print("수학점수 : %d" % math)
print("영어점수 : %d" % eng)
print("평균점수 : %.2f" % avg)
