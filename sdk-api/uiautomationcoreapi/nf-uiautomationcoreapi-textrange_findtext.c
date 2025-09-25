HRESULT TextRange_FindText(
  [in]  HUIATEXTRANGE hobj,
  [in]  BSTR          text,
  [in]  BOOL          backward,
  [in]  BOOL          ignoreCase,
  [out] HUIATEXTRANGE *pRetVal
);