UINT GetRawInputDeviceInfoA(
  [in, optional]      HANDLE hDevice,
  [in]                UINT   uiCommand,
  [in, out, optional] LPVOID pData,
  [in, out]           PUINT  pcbSize
);