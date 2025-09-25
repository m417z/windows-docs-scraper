HRESULT GetText(
  [in]  LONG       acpStart,
  [in]  LONG       acpEnd,
  [out] WCHAR      *pchPlain,
  [in]  ULONG      cchPlainReq,
  [out] ULONG      *pcchPlainRet,
  [out] TS_RUNINFO *prgRunInfo,
  [in]  ULONG      cRunInfoReq,
  [out] ULONG      *pcRunInfoRet,
  [out] LONG       *pacpNext
);