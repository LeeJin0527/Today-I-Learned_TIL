

## HTTP헤더

- header-field =field-name":" OWS field-value OWS (OWS 띄어쓰기)
- field-name은 대소문자 구분 없음

![](https://images.velog.io/images/jinii/post/574818a5-b63d-40e6-9014-d2dffc9f1e9e/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.16.40.png)

### 용도

- HTTP 전송에 필요한 모든 부가 정보
- 예) 메시지 바디의 내용 , 메시지 바디의 크기 , 압축, 인증 , 요청 클라이언트, 서버정보 , 캐시 관리 정보
- 표준 헤더가 너무 많음
- 필요시 임의의 헤더 추가 가능

**HTTP헤더 -RFC2616(과거) -현재는 폐기 됨** 

![](https://images.velog.io/images/jinii/post/59bae7f6-d9b2-4592-8dc4-61237fe9d29e/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.17.39.png)

- General 헤더 : 메시지 전체에 적용되는 정보 예)Connection : close
- Request 헤더 : 요청 정보 예) User-Agent
- Response 헤더 : 응답 정보 예) Server : Apache
- Entity 헤더 : 엔티티 바디 정보 예) Content-Type

![](https://images.velog.io/images/jinii/post/6b8c7b6d-e694-4854-9f61-bc4426cc7b91/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.21.51.png)

- **메시지 본문은 엔티티 본문을 전달하는데 사용**
- 엔티티 본문은 요청이나 응답에서 전달할 실제 데이터
- 엔티티 헤더는 엔티티 본문의 데이터를 해석할 수 있는 정보 제공(데이터 유형, 데이터 길이 , 압축 정보 등)

**2014년 RFC7230~7235 등장**

- 엔티티 → 표현
- Representation = representation Metadata + Representation Data
- 표현 = 표현 메타 데이터 + 표현 데이터

![](https://images.velog.io/images/jinii/post/3ebb5a08-9c01-4fe5-879c-fd123ebe77fb/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.24.12.png)

- 메시지 본문을 통해 표현 데이터 전달
- 메시지 본문 = 페이로드
- 표현은 요청이나 응답에서 전달할 실제 데이터
- 표현 헤더는 표현 데이터를 해석 할 수 있는 정보 제공

## 

# 표현

Content-Type: 표현 데이터의 형식

- 미디어 타입, 문자 인코딩

![](https://images.velog.io/images/jinii/post/1829f840-6629-4053-bda1-32417cd9382a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.51.06.png)

Content-Encoding : 표현데이터의 압축방식

- 표현 데이터를 압축하기 위해 사용
- 압축 후 인코딩 헤더 추가
- 데이터를 읽는 쪽에서 인코딩 헤더의 정보로 압축해제

![](https://images.velog.io/images/jinii/post/f33bbb86-5d34-432b-982b-82ac88f08fa6/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.51.53.png)

Content-Language: 표현 데이터의 자연 언어

- 표현 데이터의 자연 언어를 표현

![](https://images.velog.io/images/jinii/post/9ca2934a-8b97-471b-a18c-98b063987d9b/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.52.23.png)
Content-Length: 표현 데이터의 길이 

- 바이트 단위
- Transfer-Encoding을 사용하면 컨텐트렝쓰를 쓰면 안됨

![](https://images.velog.io/images/jinii/post/f4055f24-cc21-4edf-92d8-2a78ca8e22f6/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.53.07.png)
**표현 헤더는 전송, 응답 둘다 사용**

# 협상

- Accept : 클라이언트가 선호하는 미디어 타입 전달
- Accept-Charset: 클라이언트가 선호하는 문자 인코딩
- Accept-Encoding : 클라이언트가 선호하는 압축 인코딩
- Accept-Language : 클라이언트가 선호하는 자연언어
- 협상헤더는 요청시에만 사용

![](https://images.velog.io/images/jinii/post/4fb07da7-8f23-44da-87f7-1abb8d6ed7d7/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.55.06.png)

# 전송 방식

- Transfer-Encoding
- Range, Content-Range
- 단순 전송
- 압축 전송
- 분할 전송
- 범위 전송

# 일반정보

- Form : 유저 에이전트의 이메일 정보
- Referer: 이전 웹페이지 주소
- User-Agent : 유저 에이전트 애플리케이션 정보
- Server : 요청을 처리하는 오리진 서버의 소프트웨어의 정보
- Date : 메시지가 생성된 날짜

# 특별한 정보

- Host : 요청한 호스트 정보 (도메인)
    - 요청에서 사용
    - 필수
    - 하나의 서버가 여러 도메인을 처리해야 할 때
    - 하나의 IP 주소에 여러 도메인이 적용되어 있을 때

![](https://images.velog.io/images/jinii/post/7271d9e1-befb-4c96-a5dc-46586667e1ab/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.58.55.png)

- Location : 페이지 리다이렉션
- Allow : 허용 가능한 HTTP 메서드
- Retry-After : 유저 에이전트가 다음 요청을 하기 까지 기다려야 하는 시간

# 쿠키

- Set-Cookie : 서버에서 클라이언트로 쿠키 전달(응답)
- Cookie : 클라이언트가 서버에서 받은 쿠키를 저장하고, HTTP 요청시 서버로 전달

## Stateless

- HTTP는 무상태이다.
- 클라이언트와 서버가 요청과 응답을 주고 받으면 연결이 끊어진다.
- 클라이언트가 다시 요청하면 서버는 이전 요청을 기억하지 못한다.
- 클라이언트와 서버는 서로 상태를 유지하지 않는다.

### 쿠키 미사용

**대안 - 모든 요청에 사용자 정보 포함?**

- 모든 요청에 사용자 정보가 포함 되도록 개발 해야 함
- 브라우저를 완전히 종료하고 다시 열면?

![](https://images.velog.io/images/jinii/post/47823b58-c409-4f05-b602-42e86dca7499/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.31.41.png)
![](https://images.velog.io/images/jinii/post/64cda4b9-7c52-4242-9dd9-1d926cfcae6d/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.31.46.png)

![](https://images.velog.io/images/jinii/post/ae191720-45de-473a-a1e1-01cdd81a9e79/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-11%20%E1%84%8B%E1%85%A9%E1%84%8C%E1%85%A5%E1%86%AB%201.31.52.png)

- 예)set-cookie :sessionId=abcde1234;expires=Sat,26-Dec-2020 00:00:00 GMT;**path**=/; **domain**=.google.com; **Secure**
- 사용처
    - 사용자 로그인 세션 관리
    - 광고 정보 트래킹
- 쿠키 정보는 항상 서버에 전송됨
    - 네트워크 트래픽 추가 유발
    - 최소한의 정보만 사용(세션 id, 인증토큰)
    - 서버에 전송하지 않고, 웹 브라우저 내부에 데이터를 저장하고 싶으면 웹스토리지 참고
- 주의!
    - 보안에 민감한 데이터는 저장하면 안됨(주민번호, 신용카드 번호)
    
### 생명주기

### Expires, max-age

- Set-Cookie : **expires**=Sat,

> 	만료일이 되면 쿠키 삭제

- Set-Cookie:**max-age**=3600
> 	0이나 음수를 지정하면 쿠키 삭제
- 세션 쿠키 : 만료 날짜를 생략하면 브라우저 종료시 까지만 유지
- 영속 쿠키 : 만료 날짜를 입력하면 해당 날짜까지 유지
    

### 쿠키 -도메인

- 예) domain=example.org
- 명시 : 명시한 문서 기준 도메인 + 서브 도메인 포함
    
    domain=example.org
    
    [example.org/](http://example.org/)  [dev.example.org](http://dev.example.org) 도 쿠키 접근 
    
- 생략 : 현재 문서 기준 도메인만 적용
    - [example.org](http://example.org) 에서 쿠키를 생성하고 도메인 지정을 생략
    - [example.org](http://example.org) 만 쿠키 접근

### 쿠키 - 경로

- 예)path=/home
- 이 경로를 포함한 하위 경로 페이지만 쿠키 접근
- 일반적으로 path=/루트
- 예)
    - path=/home
    - /home/level1 → 가능
    - /hello → 불가능

### 쿠키 - 보안

### Secure, HttpOnly, SameSite

- Secure
    - 쿠키는 http, https를 구분하지 않고 전송
    - Secure를 적용하면 https인 경우에만 전송
- HttpOnly
    - XSS 공격 방지
    - 자바 스크립트에서 접근 불가
    - HTTP 전송에만 사용
- SameSite
    - XSRF 공격 방지
    - 요청 도메인과 쿠키에 설정된 도메인이 같은 경우만 쿠키 전송
