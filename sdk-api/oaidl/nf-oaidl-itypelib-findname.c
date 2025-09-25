HRESULT FindName(
  [in, out] LPOLESTR  szNameBuf,
  [in]      ULONG     lHashVal,
  [out]     ITypeInfo **ppTInfo,
  [out]     MEMBERID  *rgMemId,
  [in, out] USHORT    *pcFound
);