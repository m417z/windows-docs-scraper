typedef struct SetProviderStatusInfo {
  TimeProvState                 tpsCurrentState;
  DWORD                         dwStratum;
  LPWSTR                        wszProvName;
  HANDLE                        hWaitEvent;
  SetProviderStatusInfoFreeFunc *pfnFree;
  HRESULT                       *pHr;
  DWORD                         *pdwSysStratum;
} SetProviderStatusInfo;