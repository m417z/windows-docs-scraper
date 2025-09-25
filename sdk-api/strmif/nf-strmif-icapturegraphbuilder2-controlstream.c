HRESULT ControlStream(
  [in] const GUID     *pCategory,
  [in] const GUID     *pType,
  [in] IBaseFilter    *pFilter,
  [in] REFERENCE_TIME *pstart,
  [in] REFERENCE_TIME *pstop,
  [in] WORD           wStartCookie,
  [in] WORD           wStopCookie
);