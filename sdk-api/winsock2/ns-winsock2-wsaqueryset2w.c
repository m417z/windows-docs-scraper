typedef struct _WSAQuerySet2W {
  DWORD         dwSize;
  LPWSTR        lpszServiceInstanceName;
  LPWSAVERSION  lpVersion;
  LPWSTR        lpszComment;
  DWORD         dwNameSpace;
  LPGUID        lpNSProviderId;
  LPWSTR        lpszContext;
  DWORD         dwNumberOfProtocols;
  LPAFPROTOCOLS lpafpProtocols;
  LPWSTR        lpszQueryString;
  DWORD         dwNumberOfCsAddrs;
  LPCSADDR_INFO lpcsaBuffer;
  DWORD         dwOutputFlags;
  LPBLOB        lpBlob;
} WSAQUERYSET2W, *PWSAQUERYSET2W, *LPWSAQUERYSET2W;