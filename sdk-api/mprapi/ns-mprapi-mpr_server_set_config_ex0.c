typedef struct _MPR_SERVER_SET_CONFIG_EX0 {
  MPRAPI_OBJECT_HEADER         Header;
  DWORD                        setConfigForProtocols;
  MPRAPI_TUNNEL_CONFIG_PARAMS0 ConfigParams;
} MPR_SERVER_SET_CONFIG_EX0, *PMPR_SERVER_SET_CONFIG_EX0;