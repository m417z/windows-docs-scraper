LONG SCardIntroduceCardTypeW(
  [in]           SCARDCONTEXT hContext,
  [in]           LPCWSTR      szCardName,
  [in, optional] LPCGUID      pguidPrimaryProvider,
  [in, optional] LPCGUID      rgguidInterfaces,
  [in]           DWORD        dwInterfaceCount,
  [in]           LPCBYTE      pbAtr,
  [in]           LPCBYTE      pbAtrMask,
  [in]           DWORD        cbAtrLen
);