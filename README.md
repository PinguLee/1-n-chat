# 1:N Chat
- 여러명의 클라인트끼리 채팅을 할 수 있는 프로그램 서버
- TCP/IP Socket Practice

## 참고
- 윈도우 소켓 : https://learn.microsoft.com/ko-kr/windows/win32/api/winsock2/nf-winsock2-socket
- 리눅스 소켓 : https://man7.org/linux/man-pages/man2/socket.2.html
- 포트 종류 : https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml
- 가이드 : https://beej.us/guide/bgnet/html/split/

## To-do
- [x] Socket을 사용하여 Server과 Client 연결
- [x] 오류에 대한 예외 처리 (문제가 있다면 exit 1 없다면 exit 0)
- [ ] 최대 16개 클라이언트 연결
- [x] 메모리 동적 할당
- [ ] select를 사용한 멀티플렉싱
