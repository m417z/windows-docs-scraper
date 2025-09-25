LONG SCardLocateCardsW(
  [in]      SCARDCONTEXT         hContext,
  [in]      LPCWSTR              mszCards,
  [in, out] LPSCARD_READERSTATEW rgReaderStates,
  [in]      DWORD                cReaders
);