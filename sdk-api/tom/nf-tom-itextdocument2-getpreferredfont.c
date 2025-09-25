HRESULT GetPreferredFont(
  [in]  long cp,
  [in]  long CharRep,
  [in]  long Options,
  [in]  long curCharRep,
  [in]  long curFontSize,
  [out] BSTR *pbstr,
  [out] long *pPitchAndFamily,
  [out] long *pNewFontSize
);