DWORD RasEapInvokeConfigUI(
  [in]  DWORD dwEapTypeId,
  [in]  HWND  hwndParent,
  [in]  DWORD dwFlags,
  [in]  BYTE  *pConnectionDataIn,
  [in]  DWORD dwSizeOfConnectionDataIn,
  [out] BYTE  **ppConnectionDataOut,
  [out] DWORD *pdwSizeOfConnectionDataOut
);