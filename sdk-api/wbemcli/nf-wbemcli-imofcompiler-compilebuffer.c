HRESULT CompileBuffer(
  [in]      long                     BuffSize,
  [in]      BYTE                     *pBuffer,
  [in]      LPWSTR                   ServerAndNamespace,
  [in]      LPWSTR                   User,
  [in]      LPWSTR                   Authority,
  [in]      LPWSTR                   Password,
  [in]      LONG                     lOptionFlags,
  [in]      LONG                     lClassFlags,
  [in]      LONG                     lInstanceFlags,
  [in, out] WBEM_COMPILE_STATUS_INFO *pInfo
);