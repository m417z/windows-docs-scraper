HRESULT CreateMSPCallHelper(
  CMSPAddress *pCMSPAddress,
  MSP_HANDLE  htCall,
  DWORD       dwReserved,
  DWORD       dwMediaType,
  IUnknown    *pOuterUnknown,
  IUnknown    **ppMSPCall,
  T           **ppCMSPCall
);