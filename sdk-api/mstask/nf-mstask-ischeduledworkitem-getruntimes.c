HRESULT GetRunTimes(
  [in]      const LPSYSTEMTIME pstBegin,
  [in]      const LPSYSTEMTIME pstEnd,
  [in, out] WORD               *pCount,
  [out]     LPSYSTEMTIME       *rgstTaskTimes
);