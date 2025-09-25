typedef struct _BTH_ENUMERATOR_INFO {
  ENUMERATOR_TYPE   EnumeratorType;
  ENUMERATOR_ACTION Action;
  ULONG             Port;
  ULONG             Flags;
  GUID              Guid;
  ULONG             InstanceId;
  WCHAR             InstanceIdStr[BTH_MAX_SERVICE_NAME_SIZE];
  USHORT            Vid;
  USHORT            Pid;
  USHORT            Mfg;
  USHORT            LocalMfg;
  USHORT            VidType;
  WCHAR             ServiceName[BTH_MAX_SERVICE_NAME_SIZE];
  CHAR              SdpPriLangServiceName[BTH_MAX_SERVICE_NAME_SIZE];
  WCHAR             DeviceString[BTH_MAX_SERVICE_NAME_SIZE];
} BTH_ENUMERATOR_INFO, *PBTH_ENUMERATOR_INFO;