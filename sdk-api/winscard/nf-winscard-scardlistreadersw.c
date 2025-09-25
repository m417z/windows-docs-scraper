LONG SCardListReadersW(
  [in]           SCARDCONTEXT hContext,
  [in, optional] LPCWSTR      mszGroups,
  [out]          LPWSTR       mszReaders,
  [in, out]      LPDWORD      pcchReaders
);