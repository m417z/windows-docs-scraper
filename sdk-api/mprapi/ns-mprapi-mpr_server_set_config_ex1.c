typedef struct _MPR_SERVER_SET_CONFIG_EX1 {
  MPRAPI_OBJECT_HEADER         Header;
  DWORD                        setConfigForProtocols;
  MPRAPI_TUNNEL_CONFIG_PARAMS1 ConfigParams;
} MPR_SERVER_SET_CONFIG_EX1, *PMPR_SERVER_SET_CONFIG_EX1;