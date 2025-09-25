typedef struct {
  DWORD           dwStructSize;
  LPSTR           lpszScheme;
  DWORD           dwSchemeLength;
  INTERNET_SCHEME nScheme;
  LPSTR           lpszHostName;
  DWORD           dwHostNameLength;
  INTERNET_PORT   nPort;
  LPSTR           lpszUserName;
  DWORD           dwUserNameLength;
  LPSTR           lpszPassword;
  DWORD           dwPasswordLength;
  LPSTR           lpszUrlPath;
  DWORD           dwUrlPathLength;
  LPSTR           lpszExtraInfo;
  DWORD           dwExtraInfoLength;
} URL_COMPONENTSA, *LPURL_COMPONENTSA;