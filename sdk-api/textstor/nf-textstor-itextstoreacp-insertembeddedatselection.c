HRESULT InsertEmbeddedAtSelection(
  [in]  DWORD         dwFlags,
  [in]  IDataObject   *pDataObject,
  [out] LONG          *pacpStart,
  [out] LONG          *pacpEnd,
  [out] TS_TEXTCHANGE *pChange
);