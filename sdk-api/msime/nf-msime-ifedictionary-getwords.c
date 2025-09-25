HRESULT GetWords(
  [in]      const WCHAR *pwchFirst,
  [in]      const WCHAR *pwchLast,
  [in]      const WCHAR *pwchDisplay,
  [in]      ULONG       ulPos,
  [in]      ULONG       ulSelect,
  [in]      ULONG       ulWordSrc,
  [in, out] UCHAR       *pchBuffer,
  [in]      ULONG       cbBuffer,
  [out]     ULONG       *pcWrd
);