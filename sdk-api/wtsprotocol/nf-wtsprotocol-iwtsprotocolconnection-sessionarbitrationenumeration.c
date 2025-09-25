HRESULT SessionArbitrationEnumeration(
  [in]      HANDLE_PTR hUserToken,
  [in]      BOOL       bSingleSessionPerUserEnabled,
  [out]     ULONG      *pSessionIdArray,
  [in, out] ULONG      *pdwSessionIdentifierCount
);