LONG SCardListReadersA(
  [in]           SCARDCONTEXT hContext,
  [in, optional] LPCSTR       mszGroups,
  [out]          LPSTR        mszReaders,
  [in, out]      LPDWORD      pcchReaders
);