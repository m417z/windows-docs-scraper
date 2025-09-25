HRESULT GetInfoOfIndex(
  [in]  ULONG     iti,
  [in]  DWORD     dwFlags,
  [out] ITypeInfo **pptiCoClass,
  [out] DWORD     *pdwTIFlags,
  [out] ULONG     *pcdispidReserved,
  [out] IID       *piidPrimary,
  [out] IID       *piidSource
);