HRESULT RouterInvokeCredentialsUI(
  DWORD     dwEapTypeId,
  ULONG_PTR uConnectionParam,
  HWND      hwndParent,
  DWORD     dwFlags,
  BYTE      *pConnectionDataIn,
  DWORD     dwSizeOfConnectionDataIn,
  BYTE      *pUserDataIn,
  DWORD     dwSizeOfUserDataIn,
  BYTE      **ppUserDataOut,
  DWORD     *pdwSizeOfUserDataOut
);