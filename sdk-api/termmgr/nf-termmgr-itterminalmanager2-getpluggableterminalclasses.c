HRESULT GetPluggableTerminalClasses(
  [in]      IID   iidSuperclass,
  [in]      DWORD dwMediaTypes,
  [in, out] DWORD *pdwNumClasses,
  [out]     IID   *pTerminalClasses
);