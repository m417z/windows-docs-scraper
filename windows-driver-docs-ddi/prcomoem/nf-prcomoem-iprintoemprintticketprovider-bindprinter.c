HRESULT BindPrinter(
  [in]  HANDLE     hPrinter,
  [in]  INT        version,
  [out] POEMPTOPTS pOptions,
  [out] INT        *cNamespaces,
  [out] BSTR       **ppNamespaces
);