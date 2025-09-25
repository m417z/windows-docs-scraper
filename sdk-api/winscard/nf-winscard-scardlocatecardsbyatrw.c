LONG SCardLocateCardsByATRW(
  [in]      SCARDCONTEXT         hContext,
  [in]      LPSCARD_ATRMASK      rgAtrMasks,
  [in]      DWORD                cAtrs,
  [in, out] LPSCARD_READERSTATEW rgReaderStates,
  [in]      DWORD                cReaders
);