LONG SCardLocateCardsA(
  [in]      SCARDCONTEXT         hContext,
  [in]      LPCSTR               mszCards,
  [in, out] LPSCARD_READERSTATEA rgReaderStates,
  [in]      DWORD                cReaders
);