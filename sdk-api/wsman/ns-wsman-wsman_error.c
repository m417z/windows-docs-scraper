typedef struct _WSMAN_ERROR {
  DWORD  code;
  PCWSTR errorDetail;
  PCWSTR language;
  PCWSTR machineName;
  PCWSTR pluginName;
} WSMAN_ERROR;