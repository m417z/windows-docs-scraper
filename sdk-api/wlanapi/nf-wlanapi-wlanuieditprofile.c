DWORD WlanUIEditProfile(
  [in]  DWORD             dwClientVersion,
  [in]  LPCWSTR           wstrProfileName,
  [in]  GUID              *pInterfaceGuid,
  [in]  HWND              hWnd,
  [in]  WL_DISPLAY_PAGES  wlStartPage,
        PVOID             pReserved,
  [out] PWLAN_REASON_CODE pWlanReasonCode
);