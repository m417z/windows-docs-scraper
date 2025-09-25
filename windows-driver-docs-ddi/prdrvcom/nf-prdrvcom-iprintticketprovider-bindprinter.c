HRESULT BindPrinter(
  [in]  IN HANDLE     hPrinter,
  [in]  IN INT        version,
  [out] OUT PSHIMOPTS pOptions,
  [out] OUT DWORD     *pDevModeFlags,
  [out] OUT INT       *cNamespaces,
  [out] OUT BSTR      **ppNamespaces
);