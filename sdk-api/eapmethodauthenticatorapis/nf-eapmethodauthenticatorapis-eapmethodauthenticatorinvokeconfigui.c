DWORD EapMethodAuthenticatorInvokeConfigUI(
  [in]  EAP_METHOD_TYPE *pEapMethodType,
  [in]  HWND            hwndParent,
  [in]  DWORD           dwFlags,
  [in]  LPCWSTR         pwszMachineName,
  [in]  DWORD           dwSizeOfConfigIn,
  [in]  BYTE            *pConfigIn,
  [out] DWORD           *pdwSizeOfConfigOut,
  [out] BYTE            **ppConfigOut,
  [out] EAP_ERROR       **ppEapError
);