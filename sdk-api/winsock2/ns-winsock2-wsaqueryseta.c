typedef struct _WSAQuerySetA {
  DWORD         dwSize;
  LPSTR         lpszServiceInstanceName;
  LPGUID        lpServiceClassId;
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
} WSAQUERYSETA, *PWSAQUERYSETA, *LPWSAQUERYSETA;