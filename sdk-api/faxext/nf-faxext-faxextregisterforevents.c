HANDLE FaxExtRegisterForEvents(
  [in] HINSTANCE                 hInst,
  [in] DWORD                     dwDeviceId,
  [in] FAX_ENUM_DEVICE_ID_SOURCE DevIdSrc,
  [in] LPCWSTR                   lpcwstrDataGUID,
  [in] PFAX_EXT_CONFIG_CHANGE    lpConfigChangeCallback
);