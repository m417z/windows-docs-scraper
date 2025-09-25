typedef struct _DD_GETDRIVERSTATEDATA {
  DWORD   dwFlags;
  union {
    PDD_DIRECTDRAW_GLOBAL lpDD;
    DWORD_PTR             dwhContext;
  };
  LPDWORD lpdwStates;
  DWORD   dwLength;
  HRESULT ddRVal;
} *PDD_GETDRIVERSTATEDATA, DD_GETDRIVERSTATEDATA;