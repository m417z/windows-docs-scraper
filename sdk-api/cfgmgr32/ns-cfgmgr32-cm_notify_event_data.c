typedef struct _CM_NOTIFY_EVENT_DATA {
  CM_NOTIFY_FILTER_TYPE FilterType;
  DWORD                 Reserved;
  union {
    struct {
      GUID  ClassGuid;
      WCHAR SymbolicLink[ANYSIZE_ARRAY];
    } DeviceInterface;
    struct {
      GUID  EventGuid;
      LONG  NameOffset;
      DWORD DataSize;
      BYTE  Data[ANYSIZE_ARRAY];
    } DeviceHandle;
    struct {
      WCHAR InstanceId[ANYSIZE_ARRAY];
    } DeviceInstance;
  } u;
} CM_NOTIFY_EVENT_DATA, *PCM_NOTIFY_EVENT_DATA;