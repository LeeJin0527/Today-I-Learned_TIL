
AWS 클라우드 기초 ( 2021.05.01)
updated (2021.05.02)


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
	- 이름 태그 : testIGW
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
	
AWS management console --> service -> EC2 

인스턴스 

	--> 우측 상단 [인스턴스 시작] 버튼 클릭 

	단계 1. AMI 선택 
	
	Amazon Linux 2 AMI [선택]
	
	단계 2. 인스턴스 유형 선택 
	
	t3.2xlarge 
	
		--> [다음: 인스턴스 세부정보 구성]
		
	단계 3. 인스턴스 세부 정부 구성 
	
		네트워크 : testVPC
		
		서브넷 : public subnet A1
		
		--> [다음: 스토리지 추가]
		
	단계 4. 스토리지 추가 
	
		8G ssd 
		
		--> [다음 : 태그 추가]
		
	단계 5. 태그 추가 
	
		--> 태그 추가 버튼 
		
		---> 키 Name   값 web server 
		
		--> [다음: 보안그룹 구성]
		
	단계 6 : 보안 그룹 구성 
	
		--> 보안 그룹 이름 : web server fw
	
		--> 소스 : 위치 무관 
		
		--> 검토 및 시작 

	[시작하기] 버튼 클릭 
	
	기존 키 페어 선택 또는 새 키 페어 생성 
	
	--> 새 키 페어 생성 
	
	--> 키 페어 이름 : webserver
	
	[키 페어 다운로드] --> 다운로드 받은 키 확인 
	
	[인스턴스 시작]










Elastic IP (EC2 인스턴스 고정 public IP )

EC2  --> 탄력적 IP (Elastic IP )

	--> [탄력적 IP 주소 할당 ] 버튼 클릭 
	
	--> Amazon 의 IPv4 주소 풀 
	
	--> Name : Web server IP 
	
	--> [할당]
	
	
	--> 할당 받은 Elastic IP 선택 
	
	--> [작업] --> 탄력적 IP 주소 연결 
	
	- 리소스 유형 : 인스턴스 
	
	- 인스턴스 : web server 
	
	- 재연결 : 이 탄력적 IP 주소를 재연결하도록 허용(V)
	
	[연결] 
	


pwd 

위치가 --> webserver.pem 파일의 위치 

cd 


chmod 600 webserver.pem

ssh   -i     webserver.pem    -l     ec2-user    ip
















lsblk    (list block : 시스템 연결에 디스크 목록)

NAME          MAJ:MIN RM SIZE RO TYPE MOUNTPOINT

nvme0n1       259:0    0   8G  0 disk

├─nvme0n1p1   259:1    0   8G  0 part /

└─nvme0n1p128 259:2    0   1M  0 part

웹 서비스 구축 

$ sudo yum install -y httpd 

	--> apache web service 설치 
	
$ sudo systemctl enable httpd 

	--> 시스템 부팅시 자동으로 웹 서비스 시작 
	
$ sudo systemctl start httpd 

	--> 지금 웹 서비스 시작 
	
$ sudo  chmod   777  /var/www/html

$ echo "Hello world"   >>  /var/www/html/index.html 

	--> 서비스할 웹 페이지 생성 


웹 브라우저 (크롬) 

http://ip/index.html

http (80 port)











EC2 --> 보안 그룹 --> web server fw --> 인바운트 규칙 --> 인바운드 규칙 편집 

[규칙 추가] 

유형 (HTTP) 소스 (위치무관)

[규칙 저장]


$ lsblk 

$ sudo   mkfs  -t ext4   /dev/nvme1n1

$ sudo  mount  /dev/nvme1n1   /mnt 


$ sudo df -hT 





























