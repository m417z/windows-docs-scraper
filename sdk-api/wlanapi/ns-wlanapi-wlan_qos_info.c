typedef struct _WLAN_QOS_INFO {
  WLAN_QOS_CAPABILITIES    interfaceCapabilities;
  BOOL                     bConnected;
  WLAN_CONNECTION_QOS_INFO connectionQoSInfo;
} WLAN_QOS_INFO, *PWLAN_QOS_INFO;