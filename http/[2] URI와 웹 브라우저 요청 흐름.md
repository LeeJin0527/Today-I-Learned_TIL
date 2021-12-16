_URI
웹 브라우저 요청 흐름_

# URI (Uniform Resource Identifier)

![](https://images.velog.io/images/jinii/post/94312d9b-b8d4-485f-a201-90506dd842dd/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%201.06.54.png)
### URI

**Uniform : 리소스를 식별하는 통일된 방식**

**Resource : 자원 , URI 로 구분 할 수 있는 모든 것(제한 없음)**

**Identifier : 다른 항목과 구분하는데 필요한 정보**

URL : Uniform Resource Locator : 리소스가 있는 위치를 지정
URN :Uniform Resouce Name : 리소스에게 이름을 부여

위치는 변할 수 있지만 , 이름은 변하지 않는다.

URN 만으로는 실제 리소스를 찾을 수 있는 방법이 보편화 되어있지 않음.

![](https://images.velog.io/images/jinii/post/5d46fb2a-a44b-4a7a-8361-8f827adf4e1a/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%201.14.31.png)
- **scheme://[userinfo@]host[:port][/path][?query][#fragment]**
- [https://www.google.com:443/search?q=hello&hl=ko](https://www.google.com/search?q=hello&hl=ko)

- 프로토콜 : https
- 호스트명 : www.google.com
- 포트번호 :443
- 경로 : /search
- 쿼리 파라미터 :( q = hello&hl=ko)

## URL

### scheme:

- 주로 프로토콜 사용
- 프로토콜 : 어떤 방식으로 자원에 접근할 것인가에 대한 약속 규칙
- http :80 https: 443 포트는 생략 가능
- https 는 http 에 보안 기능 추가

### userinfo:

- URL에 사용자 정보를 포함해서 인증
- 거의 사용하지 않음

### host:

- 호스트명
- 도메인명 이나 IP 주소 모두 사용 가능

### port:

- 포트(PORT)
- 접속 포트
- 일반적으로 생략

### path:

- 리소스 경로, 계층적 구조

### query:

- key = value 형태
- ?로 시작 &로 추가 가능 ?keyA=valueA&keyB=valueB
- query parameter, query string 등으로 불림, 웹서버에 제공하는 파라미터, 문자 형태
- 숫자로 들어와도 문자열로 인식

### fragment:

- html 내부 북마크에 사용
- 서버에 전송하는 정보가 아님

# 웹 브라우저 요청 흐름

![](https://images.velog.io/images/jinii/post/29a24c6b-3d27-4afa-a501-ee6d325f8347/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%201.34.51.png)

1. 웹 브라우저가 호스트명을 보고 DNS를 조회하여 IP 를 얻는다.
2. 그리고 HTTP 요청 메시지를 생성한다.
3. 그리고 HTTP 메시지를 전송한다.
4. 서버는 응답 메시지를 생성하여 패킷에 감싸 보낸다.
5. 클라이언트는 패킷에 있는 정보를 가지고 렌더링을 하여 웹브라우저에 나타낸다.

> **조회/ 뭔가를 검색할게~/ 쿼리 / http 버전/ 호스트명**
![](https://images.velog.io/images/jinii/post/a65b32d3-504b-49f4-9229-0604d2b385a7/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%201.36.35.png)

> 다음과 같은 과정을 통해 전달 (자세한건 [1]에 있음 )
![](https://images.velog.io/images/jinii/post/0351bd62-4d40-411c-a62d-5caaad698fa9/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%201.36.53.png)

> **http버전/ 응답 ok/ 타입은 HTML로 내려줄게 / 길이는 3423이야/ HTML 내용**
![](https://images.velog.io/images/jinii/post/ac12d332-aa62-47cb-9899-383acf683140/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%201.37.34.png)
