HRESULT RouterInvokeConfigUI(
  DWORD     dwEapTypeId,
  ULONG_PTR uConnectionParam,
  HWND      hwndParent,
  DWORD     dwFlags,
  BYTE      *pConnectionDataIn,
  DWORD     dwSizeOfConnectionDataIn,
  BYTE      **ppConnectionDataOut,
  DWORD     *pdwSizeOfConnectionDataOut
);