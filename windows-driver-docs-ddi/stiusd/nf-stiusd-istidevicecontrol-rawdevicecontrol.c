HRESULT RawDeviceControl(
  USD_CONTROL_CODE EscapeFunction,
  LPVOID           lpInData,
  DWORD            cbInDataSize,
  LPVOID           pOutData,
  DWORD            dwOutDataSize,
  LPDWORD          pdwActualData
);