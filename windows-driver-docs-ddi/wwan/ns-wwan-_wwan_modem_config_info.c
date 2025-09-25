typedef struct _WWAN_MODEM_CONFIG_INFO {
  WWAN_MODEM_CONFIG_MODE   ConfigMode;
  WWAN_MODEM_CONFIG_STATE  ConfigState;
  WWAN_MODEM_CONFIG_REASON ConfigReason;
  WWAN_MODEM_CONFIG_ID     PreviousConfigID;
  WWAN_MODEM_CONFIG_ID     CurrentConfigID;
  DWORD                    IsCurrentConfigDefault;
  WCHAR                    ConfigName[WWAN_CONFIGNAME_LEN];
  WWAN_LIST_HEADER         NSSAIListHeader;
} WWAN_MODEM_CONFIG_INFO, *PWWAN_MODEM_CONFIG_INFO;