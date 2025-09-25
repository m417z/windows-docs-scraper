typedef struct RILUICCRESPONSE {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwStatusWord1;
  DWORD dwStatusWord2;
  DWORD dwResponseSize;
  BYTE  pbResponse[1];
} RILUICCRESPONSE, *LPRILUICCRESPONSE;