typedef struct _WLAN_CONNECTION_NOTIFICATION_DATA {
  WLAN_CONNECTION_MODE wlanConnectionMode;
  WCHAR                strProfileName[WLAN_MAX_NAME_LENGTH];
  DOT11_SSID           dot11Ssid;
  DOT11_BSS_TYPE       dot11BssType;
  BOOL                 bSecurityEnabled;
  WLAN_REASON_CODE     wlanReasonCode;
  DWORD                dwFlags;
  WCHAR                strProfileXml[1];
} WLAN_CONNECTION_NOTIFICATION_DATA, *PWLAN_CONNECTION_NOTIFICATION_DATA;