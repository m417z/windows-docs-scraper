LONG SCardGetStatusChangeW(
  [in]      SCARDCONTEXT         hContext,
  [in]      DWORD                dwTimeout,
  [in, out] LPSCARD_READERSTATEW rgReaderStates,
  [in]      DWORD                cReaders
);