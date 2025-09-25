LONG SCardListReadersWithDeviceInstanceIdA(
  [in]            SCARDCONTEXT hContext,
  [in]            LPCSTR       szDeviceInstanceId,
  [out, optional] LPSTR        mszReaders,
  [in, out]       LPDWORD      pcchReaders
);