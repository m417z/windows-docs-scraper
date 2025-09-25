DWORD FaxExtSetData(
  [in] HINSTANCE                 hInst,
  [in] DWORD                     dwDeviceId,
  [in] FAX_ENUM_DEVICE_ID_SOURCE DevIdSrc,
  [in] LPCWSTR                   lpcwstrDataGUID,
  [in] LPBYTE                    pData,
  [in] DWORD                     dwDataSize
);