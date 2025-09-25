HRESULT VarTokenizeFormatString(
  [in, optional] LPOLESTR pstrFormat,
  [in, out]      LPBYTE   rgbTok,
  [in]           int      cbTok,
  [in]           int      iFirstDay,
  [in]           int      iFirstWeek,
  [in]           LCID     lcid,
  [in, optional] int      *pcbActual
);