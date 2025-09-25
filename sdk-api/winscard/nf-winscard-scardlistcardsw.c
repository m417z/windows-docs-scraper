LONG SCardListCardsW(
  [in]           SCARDCONTEXT hContext,
  [in, optional] LPCBYTE      pbAtr,
  [in]           LPCGUID      rgquidInterfaces,
  [in]           DWORD        cguidInterfaceCount,
  [out]          WCHAR        *mszCards,
  [in, out]      LPDWORD      pcchCards
);