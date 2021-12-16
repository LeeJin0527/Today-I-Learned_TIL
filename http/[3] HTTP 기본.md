# HTTP 기본

[모든 것이 HTTP]

[클라이언트 서버 구조]

[Stateful, Stateless]

[비연결성(Connectless)]

[HTTP 메시지]

## HTTP(HyperText Transfer Protocol)

### 모든 것이 HTTP

HTTP 메시지에 모든 것을 전송

- HTML, TEXT
- IMAGE, 음성, 영상, 파일
- JSON, XML(API)
- 거의 모든형태의 데이터 전송 가능
- 서버간에 데이터를 주고 받을 때도 대부분 HTTP 사용

### HTTP 역사

- HTTP/0.9  1991년 : GET 메서드만 지원, HTTP 헤더X
- HTTP/1.0 1996년: 메서드, 헤더 추가
- **HTTP/1.1 1997년 : 가장 많이 사용 , 가장 중요한 버전**
    
    **RFC2068 (1997) -> RFC2616 (1999) -> RFC7230~7235 (2014)**
    
- HTTP/2  2015년 :성능 개선
- HTTP/3  진행중 : TCP 대신 UDP 사용 성능 개선

**네이버는 h2 와 1.1을 많이 사용**

![](https://images.velog.io/images/jinii/post/53e34923-3d31-4980-8c93-e7df13c697fe/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%203.13.45.png)

### 기반 프로토콜

TCP: HTTP/1.1, HTTP/2

UDP: HTTP/3

**HTTP 특징**

- 클라이언트 서버 구조
- 무상태 프로토콜(Stateless), 비연결성 (Connectless)
- HTTP 메시지
- 단순함, 확장 가능

### 클라이언트 서버 구조

- Request, Response 구조
- 클라이언트는 서버에 요청을 보내고 응답 대기
- 서버는 요청에 대한 응답을 만들어 전달

### 무상태 프로토콜(Stateless)

- 서버가 클라이언트의 상태를 보존하지 않는다.
- 장점 : 서버 확장성이 높다.(스케일 아웃)
- 클라이언트가 추가 데이터를 전송해야 한다.

정말 같은 시간에 딱 맞추어 발생하는 대용량 트래픽
• 예) 선착순 이벤트, 명절 KTX 예약, 학과 수업 등록
• 예) 저녁 6:00 선착순 1000명 치킨 할인 이벤트 -> 수만명 동시 요청

Stateful vs Stateless

![](https://images.velog.io/images/jinii/post/984d455d-bc99-4cb5-949d-6f1c534f5641/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.08.50.png)

![](https://images.velog.io/images/jinii/post/60780208-d929-41be-a163-ab5655fa559e/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.08.58.png)
![](https://images.velog.io/images/jinii/post/423ed729-6baf-402b-941e-8abeae57faff/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.09.05.png)
![](https://images.velog.io/images/jinii/post/5cc08961-e8b6-4fa6-8454-6fc6367c2226/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.09.12.png)
![](https://images.velog.io/images/jinii/post/e900a67a-2160-4a07-a565-713fc93f1833/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.09.17.png)

### Stateful, Stateless 차이

상태 유지: 중간에 다른 점원으로 바뀌면 안된다.

(중간에 점원이 바뀌면 그 전까지의 정보를 알려주어야 한다.) 

무상태 : 중간에 다른 점원으로 바꿔도 된다.

클라이언트 요청이 증가해도 서버를 대거 투입 할 수 있다.

무상태는 응답 서버를 쉽게 바꿀 수 있다.→ 무한한 서버 증설 가능

# Stateless

- 모든 것을 무상태로 설계 할 수 있는 경우도 있고 없는 경우도 있다.
- 무상태 예) 로그인이 필요없는 단순 소개 화면
- 상태유지 예) 로그인
- 로그인 한 사용자의 경우 로그인 상태를 서버에 유지
- 일반적으로 브라우저 쿠키와 세션으로 유지
- 상태 유지는 최소한의 사용

## 비 연결성 Connectionless

![](https://images.velog.io/images/jinii/post/02265c61-9911-49cf-86e5-69e5ff513029/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.18.03.png)

![](https://images.velog.io/images/jinii/post/048f78cc-508d-458f-af5e-b66cfc94964b/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.13.46.png)

# 비연결성

- HTTP는 기본적으로 비연결성이다
- 일반적으로 초 단위의 빠른 속도로 응답
- 1시간 동안 수천명이 사용해도 동시에 처리하는 요청은 수십개 정도 밖에 안됨

왜냐하면 웹 브라우저에서 계속 연속해서 검색 버튼을 누르지는 않기 때문이다

- 서버 자원을 효율적으로 사용할 수 있다.

한계와 극복

- TCP/IP 연결을 새로 맺어야 함
- HTML외의 다른 여러 자원들도 다운로드 됨
- 지금은 HTTP **지속 연결**로 해결
- HTTP/2 HTTP/3 으로 최적화

![](https://images.velog.io/images/jinii/post/d3c3b627-85a8-4cfe-b0d1-2736028d8a41/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.23.44.png)

![](https://images.velog.io/images/jinii/post/c4540bb8-f13c-4c58-85d0-a779f3f51aba/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.23.48.png)
# HTTP 메시지

![](https://images.velog.io/images/jinii/post/9ac01e4b-fd87-4945-b373-b380ec7e4dc1/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%206.26.40.png)

HTTP 메시지는 시작라인, 헤더, 공백라인, 바디 로 이루어져 있음 

요청과 응답의 메시지는 조금 다름

## 시작라인

### <요청>

**start-line = request-line / status-line
• request-line = method SP(공백) request-target SP HTTP-version CRLF(엔터)**

- **HTTP 메소드(GET) POST, PUT, DELETE**
1. GET :리소스 조회
2. POST: 요청 내역 처리 
- **요청 대상 (/search?q=hello&hl=ko)**

절대 경로 쿼리 

- **HTTP version HTTP/1.1**

### <응답>

**start-line = request-line / status-line
• status-line = HTTP-version SP status-code SP reason-phrase CRLF**

- HTTP 버전
- HTTP 상태코드
1. 100 : 응답
2. 200: 성공
3. 300: 리다이렉션
4. 400:클라이언트 오류
5. 500: 서버 오류
- 이유 문구: 사람이 알아 볼 수 있도록 간단하게 표시

## 헤더

**header-field = field-name ":" OWS field-value OWS (OWS:띄어쓰기 허용)
• field-name은 대소문자 구문 없음**

- HTTP 전송 에 필요한 모든 부가 정보

예)

메시지 바디의 내용, 메시지 바디의 크기, 압축, 인증, 요청 클라이언트(브라우저) 정보,
서버 애플리케이션 정보, 캐시 관리 정보.

- 표준 헤더가 너무 많음
- 필요시 임의의 헤더 추가 가능

## 메시지 바디

- 실제 전송할 데이터
- HTML 문서, 이미지, 영상, JSON 등등 byte로 표현할 수 있는 모든 데이터 전송 가능

HTTP 는 단순하고 확장성이 좋다
