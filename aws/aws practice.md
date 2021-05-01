
AWS 클라우드 기초 ( 2021.05.01 ) 


퍼블릭 클라우드 (public cloud)
	1) Amazon (AWS)
	2) MS (Azure)
	3) Google ( GCP , google cloud platform




AWS 관리 콘솔 --> services --> vpc 

vpc 
	--> vpc 생성 버튼 클릭 	
	- 이름 태그 : testVPC 
	- IPv4 CIDR : 10.0.0.0/16
	- 태그 
	--> VPC 생성 버튼 


IGW (internet gateway) 

인터넷 게이트웨이 

	--> 인터넷 게이트웨이 생성 버튼 클릭 
	- 이름 태그 : testIGWå
	- Name : testIGW
	--> 인터넷 게이트웨이 생성 클릭 
	
	생성된 IGW 선택 
	--> [작업] --> VPC 에 연결 
	- testVPC 
	--> 인터넷 게이트웨이 연결


서브넷 
	-->  우측 사단 [서브넷 생성] 클릭 
	- VPC ID : (testVPC)

1/2 	서브넷 이름  : public subnet A1
	가용영역 (AZ) : ap-northeast-2a
	IPv4 CIDR : 10.0.1.0/24 
	Name : public subnet A1

	[새 서브넷 추가]

2/2	서브넷 이름 : private subnet B1
	가용영영(AZ) : ap-northeast-2a
	IPv4 CIDR : 10.0.2.0/24
	Name : private subnet B1

	[서브넷 생성] 클릭 

라우팅 테이블 
	--> 우측 상단 [라우팅 테이블 생성] 
	- 이름 태그 : public route 
	- VPC : testVPC 
	--> [생성] 

	생성된 "public route" 선택 
	- 라우팅 
	10.0.0.0/16   --> local 
	--> [라우팅 편집] 버튼 클릭 
	--> [라우팅 추가] 버튼 클릭 
	(대상) : 0.0.0.0/0   --> IGW (testIGW)

	- 서브넷 연결 
	public subnet A1 선택 --> [저장] 
서브넷
	 public subnet A1 선택 
	--> [작업] 선택  
	--> 자동 IP 할당 설정 수정 
	- 퍼블릭 IPv4 주소 자동 할당 활성화 체크 
	--> [저장] 
	
	속성 
	퍼블픽 IPv4 주소 자동 할당 (예)




















