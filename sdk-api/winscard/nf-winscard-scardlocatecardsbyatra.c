LONG SCardLocateCardsByATRA(
  [in]      SCARDCONTEXT         hContext,
  [in]      LPSCARD_ATRMASK      rgAtrMasks,
  [in]      DWORD                cAtrs,
  [in, out] LPSCARD_READERSTATEA rgReaderStates,
  [in]      DWORD                cReaders
);