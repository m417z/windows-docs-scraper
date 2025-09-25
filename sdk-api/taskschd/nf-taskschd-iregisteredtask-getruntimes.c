HRESULT GetRunTimes(
  [in]      const LPSYSTEMTIME pstStart,
  [in]      const LPSYSTEMTIME pstEnd,
  [in, out] DWORD              *pCount,
  [out]     LPSYSTEMTIME       *pRunTimes
);