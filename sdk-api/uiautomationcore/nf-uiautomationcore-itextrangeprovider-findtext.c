HRESULT FindText(
  [in]          BSTR               text,
  [in]          BOOL               backward,
  [in]          BOOL               ignoreCase,
  [out, retval] ITextRangeProvider **pRetVal
);