HRESULT CreateMSPCall(
  [in]  MSP_HANDLE hCall,
  [in]  DWORD      dwReserved,
  [in]  DWORD      dwMediaType,
  [in]  IUnknown   *pOuterUnknown,
  [out] IUnknown   **ppStreamControl
);