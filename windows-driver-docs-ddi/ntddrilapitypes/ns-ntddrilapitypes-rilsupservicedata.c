typedef struct RILSUPSERVICEDATA {
  DWORD                   cbSize;
  DWORD                   dwParams;
  DWORD                   dwExecutor;
  RILSUPSERVICEDATASTATUS dwStatus;
  DWORD                   dwNetworkSSErrorCause;
  DWORD                   dwNetworkCCErrorCause;
  DWORD                   dwVendorErrorCause;
  DWORD                   dwDataSize;
  WCHAR                   wszData[1];
} RILSUPSERVICEDATA, *LPRILSUPSERVICEDATA;