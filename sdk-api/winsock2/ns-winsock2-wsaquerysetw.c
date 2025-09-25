typedef struct _WSAQuerySetW {
  DWORD         dwSize;
  LPWSTR        lpszServiceInstanceName;
  LPGUID        lpServiceClassId;
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
} WSAQUERYSETW, *PWSAQUERYSETW, *LPWSAQUERYSETW;