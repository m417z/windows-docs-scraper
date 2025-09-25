typedef struct {
  USHORT                       MajorVersion;
  USHORT                       MinorVersion;
  PVOID                        Context;
  BCLASS_QUERY_TAG             QueryTag;
  BCLASS_QUERY_INFORMATION     QueryInformation;
  BCLASS_SET_INFORMATION       SetInformation;
  BCLASS_QUERY_STATUS          QueryStatus;
  BCLASS_SET_STATUS_NOTIFY     SetStatusNotify;
  BCLASS_DISABLE_STATUS_NOTIFY DisableStatusNotify;
  PDEVICE_OBJECT               Pdo;
  PUNICODE_STRING              DeviceName;
} BATTERY_MINIPORT_INFO, *PBATTERY_MINIPORT_INFO;