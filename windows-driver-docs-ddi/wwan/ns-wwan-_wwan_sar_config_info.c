typedef struct _WWAN_SAR_CONFIG_INFO {
  WWAN_SAR_CONTROL_MODE              SarMode;
  WWAN_SAR_BACKOFF_STATE             SarBackoffStatus;
  WWAN_SAR_WIFI_HARDWARE_INTEGRATION SarWifiIntegration;
  WWAN_LIST_HEADER                   SarConfigIndexListHeader;
} WWAN_SAR_CONFIG_INFO, *PWWAN_SAR_CONFIG_INFO;