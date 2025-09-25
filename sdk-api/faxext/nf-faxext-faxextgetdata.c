DWORD FaxExtGetData(
  [in]  DWORD                     dwDeviceId,
  [in]  FAX_ENUM_DEVICE_ID_SOURCE DevIdSrc,
  [in]  LPCWSTR                   lpcwstrDataGUID,
  [out] LPBYTE                    *ppData,
  [out] LPDWORD                   lpdwDataSize
);