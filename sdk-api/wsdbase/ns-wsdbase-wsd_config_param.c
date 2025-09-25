typedef struct _WSD_CONFIG_PARAM {
  WSD_CONFIG_PARAM_TYPE configParamType;
  PVOID                 pConfigData;
  DWORD                 dwConfigDataSize;
} WSD_CONFIG_PARAM, *PWSD_CONFIG_PARAM;