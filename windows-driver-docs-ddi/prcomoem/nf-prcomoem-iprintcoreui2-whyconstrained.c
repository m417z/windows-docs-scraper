HRESULT WhyConstrained(
  [in]  POEMUIOBJ poemuiobj,
  [in]  DWORD     dwFlags,
  [in]  PCSTR     pszFeatureKeyword,
  [in]  PCSTR     pszOptionKeyword,
  [out] PZZSTR    pmszReasonList,
  [in]  DWORD     cbSize,
  [out] PDWORD    pcbNeeded
);