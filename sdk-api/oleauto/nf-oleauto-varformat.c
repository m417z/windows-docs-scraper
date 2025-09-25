HRESULT VarFormat(
  [in]           LPVARIANT pvarIn,
  [in, optional] LPOLESTR  pstrFormat,
  [in]           int       iFirstDay,
  [in]           int       iFirstWeek,
  [in]           ULONG     dwFlags,
  [out]          BSTR      *pbstrOut
);