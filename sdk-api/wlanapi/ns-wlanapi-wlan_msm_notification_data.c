typedef struct _WLAN_MSM_NOTIFICATION_DATA {
  WLAN_CONNECTION_MODE wlanConnectionMode;
  WCHAR                strProfileName[WLAN_MAX_NAME_LENGTH];
  DOT11_SSID           dot11Ssid;
  DOT11_BSS_TYPE       dot11BssType;
  DOT11_MAC_ADDRESS    dot11MacAddr;
  BOOL                 bSecurityEnabled;
  BOOL                 bFirstPeer;
  BOOL                 bLastPeer;
  WLAN_REASON_CODE     wlanReasonCode;
} WLAN_MSM_NOTIFICATION_DATA, *PWLAN_MSM_NOTIFICATION_DATA;