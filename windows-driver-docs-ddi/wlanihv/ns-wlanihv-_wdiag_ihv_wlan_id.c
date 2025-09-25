typedef struct _WDIAG_IHV_WLAN_ID {
  WCHAR          strProfileName[MS_MAX_PROFILE_NAME_LENGTH];
  DOT11_SSID     Ssid;
  DOT11_BSS_TYPE BssType;
  DWORD          dwFlags;
  DWORD          dwReasonCode;
} WDIAG_IHV_WLAN_ID, *PWDIAG_IHV_WLAN_ID;