HRESULT CreateBMOF(
  [in]      LPWSTR                   TextFileName,
  [in]      LPWSTR                   BMOFFileName,
  [in]      LPWSTR                   ServerAndNamespace,
  [in]      LONG                     lOptionFlags,
  [in]      LONG                     lClassFlags,
  [in]      LONG                     lInstanceFlags,
  [in, out] WBEM_COMPILE_STATUS_INFO *pInfo
);