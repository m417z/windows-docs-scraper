typedef struct _WSAQuerySet2A {
  DWORD         dwSize;
  LPSTR         lpszServiceInstanceName;
  LPWSAVERSION  lpVersion;
  LPSTR         lpszComment;
  DWORD         dwNameSpace;
  LPGUID        lpNSProviderId;
  LPSTR         lpszContext;
  DWORD         dwNumberOfProtocols;
  LPAFPROTOCOLS lpafpProtocols;
  LPSTR         lpszQueryString;
  DWORD         dwNumberOfCsAddrs;
  LPCSADDR_INFO lpcsaBuffer;
  DWORD         dwOutputFlags;
  LPBLOB        lpBlob;
} WSAQUERYSET2A, *PWSAQUERYSET2A, *LPWSAQUERYSET2A;