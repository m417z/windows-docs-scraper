DWORD WlanRegisterNotification(
  [in]            HANDLE                     hClientHandle,
  [in]            DWORD                      dwNotifSource,
  [in]            BOOL                       bIgnoreDuplicate,
  [in, optional]  WLAN_NOTIFICATION_CALLBACK funcCallback,
  [in, optional]  PVOID                      pCallbackContext,
  [in]            PVOID                      pReserved,
  [out, optional] PDWORD                     pdwPrevNotifSource
);