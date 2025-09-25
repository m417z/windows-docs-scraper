LONG SCardGetReaderDeviceInstanceIdA(
  [in]            SCARDCONTEXT hContext,
  [in]            LPCSTR       szReaderName,
  [out, optional] LPSTR        szDeviceInstanceId,
  [in, out]       LPDWORD      pcchDeviceInstanceId
);