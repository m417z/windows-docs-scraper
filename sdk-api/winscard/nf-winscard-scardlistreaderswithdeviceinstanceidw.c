LONG SCardListReadersWithDeviceInstanceIdW(
  [in]            SCARDCONTEXT hContext,
  [in]            LPCWSTR      szDeviceInstanceId,
  [out, optional] LPWSTR       mszReaders,
  [in, out]       LPDWORD      pcchReaders
);