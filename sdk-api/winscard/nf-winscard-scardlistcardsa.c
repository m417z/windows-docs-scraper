LONG SCardListCardsA(
  [in]           SCARDCONTEXT hContext,
  [in, optional] LPCBYTE      pbAtr,
  [in]           LPCGUID      rgquidInterfaces,
  [in]           DWORD        cguidInterfaceCount,
  [out]          CHAR         *mszCards,
  [in, out]      LPDWORD      pcchCards
);