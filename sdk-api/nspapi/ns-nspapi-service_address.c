typedef struct _SERVICE_ADDRESS {
  DWORD dwAddressType;
  DWORD dwAddressFlags;
  DWORD dwAddressLength;
  DWORD dwPrincipalLength;
#if ...
  BYTE  *lpAddress;
#else
  BYTE  *lpAddress;
#endif
#if ...
  BYTE  *lpPrincipal;
#else
  BYTE  *lpPrincipal;
#endif
} SERVICE_ADDRESS, *PSERVICE_ADDRESS, *LPSERVICE_ADDRESS;