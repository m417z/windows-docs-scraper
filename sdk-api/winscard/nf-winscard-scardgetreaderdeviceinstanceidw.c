LONG SCardGetReaderDeviceInstanceIdW(
  [in]            SCARDCONTEXT hContext,
  [in]            LPCWSTR      szReaderName,
  [out, optional] LPWSTR       szDeviceInstanceId,
  [in, out]       LPDWORD      pcchDeviceInstanceId
);