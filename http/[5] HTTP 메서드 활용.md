

# 클라이언트에서 서버로 데이터 전송

데이터 전달 방식은 크게 2가지 

- **쿼리 파라미터를 통한 데이터 전송 → GET, 주로 정렬 필터 (검색어)**
- **메시지 바디를 통한 데이터 전송 → POST, PUT, PATCH**
    
    회원가입, 상품 주문 , 리소스 등록, 리소스 변경
    

## 정적 데이터 조회

- 이미지, 정적텍스트
- 조회는 GET
- 정적 데이터는 일반적으로 단순하게 조회 가능
![](https://images.velog.io/images/jinii/post/86a1c75f-9de8-463d-82e9-7ee8312bec5b/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.22.34.png)

## 동적 데이터 조회

- 주로 검색, 게시판 목록에서 정렬 필터 (검색어)
- 조회 조건을 줄여주는 필터, 조회 결과를 정렬하는 조건
- 조회는 GET
- GET은 쿼리 파라미터 사용해서 데이터 전달

![](https://images.velog.io/images/jinii/post/473b1e8c-2eb9-40b0-bf7f-eb56e83e5867/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.23.00.png)

## HTML FORM

GET, POST만 지원 

**Content-Type : application/x-www-form-urlencoded**

 

![](https://images.velog.io/images/jinii/post/afffb3f1-39b0-4e6e-9764-aaa827ef0896/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.24.36.png)

![](https://images.velog.io/images/jinii/post/582dca5a-56ae-4642-80f1-afca9316c288/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.27.20.png)
![](https://images.velog.io/images/jinii/post/3f22ea40-c280-448b-bea0-261ef686f4aa/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.29.04.png)

## HTTP API

- 서버 to 서버 백엔드
- 앱클라이언트 -아이폰, 안드로이드
- 웹클라이언트 -AJAX
- POST, PUT, PATCH 메시지 바디를 통해 데이터 전송
- GET : 조회, 쿼리 파라미터로 데이터 전달
- Content-Type: application/json 을 주로 사용

       

![](https://images.velog.io/images/jinii/post/d27a3cb4-f339-4ef1-8079-2d4f17af5384/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.32.09.png)

# HTTP API 설계 예시

## HTTP API -컬렉션

- POST 기반 등록
- 예) 회원 관리 API 등록

## HTTP API - 스토어

 

- PUT 기반 등록
- 예) 정적 컨텐츠 관리, 원격 파일 관리

## HTTP FORM 사용

- 웹 페이지 회원 관리
- GET, POST 만 지원

회원 관리 시스템

API 설계 - POST 기반 등록 

- 회원 목록  /members → GET
- 회원 등록  /members → POST
- 회원 조회 /members/{id} → GET
- 회원 수정 /members/{id} → PATCH, PUT, POST
- 회원 삭제  /members/{id} → DELETE

## POST 기반 등록

신규 리소스 식별자 생성을 서버가 만들어줌

응답을 Location에 만들어서 넘겨줌

클라이언트는 등록될 리소스의 URI 를 모른다 

### 컬렉션

- 서버가 관리 하는 리소스 디렉토리
- 서버가 리소스의 URI를 생성하고 관리
- 여기서 컬렉션은 /members

![](https://images.velog.io/images/jinii/post/300b86cf-b9cd-4293-a7a6-04617b363a17/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-12-09%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.44.47.png)

## PUT 기반 등록

파일 관리 

- 파일 목록 /files → GET
- 파일 조회 /files/{filename} → GET
- **파일 등록 /files/{filename} →PUT**
- 파일 삭제  /files/{filename} → DELETE
- 파일 대량 등록 /files → POST

**PUT 신규 자원 특징**

- 클라이언트가 리소스 URI를 알고 있어야 한다
- 클라이언트가 직접 리소스의 URI 를 저장한다

### 스토어

- 클라이언트가 관리하는 리소스 저장소
- 클라이언트가 리소스의 URI를 알고 관리
- 여기서 스토어는 /files

### HTML FORM 사용

Validation → GET, POST 맞추기 

- HTML FORM 은 GET, POST 만 지원
- delete 쓸때는 컨트롤 URI 사용해야함
- **AJAX** 같은 기술을 사용해서 해결 가능

## 컨트롤 URI

- GET, POST만 지원하므로 제약이 있음
- 이런 제약을 해결하기 위해 동사로 된 리소스 경로 사용
- POST의 /new /edit /delete 가 컨트롤 URI
- HTTP 메소드로 해결하기 애매한 경우에 사용 ( HTTP API 포함)
