LONG SCardGetStatusChangeA(
  [in]      SCARDCONTEXT         hContext,
  [in]      DWORD                dwTimeout,
  [in, out] LPSCARD_READERSTATEA rgReaderStates,
  [in]      DWORD                cReaders
);