typedef struct _CM_NOTIFY_FILTER {
  DWORD                 cbSize;
  DWORD                 Flags;
  CM_NOTIFY_FILTER_TYPE FilterType;
  DWORD                 Reserved;
  union {
    struct {
      GUID ClassGuid;
    } DeviceInterface;
    struct {
      HANDLE hTarget;
    } DeviceHandle;
    struct {
      WCHAR InstanceId[MAX_DEVICE_ID_LEN];
    } DeviceInstance;
  } u;
} CM_NOTIFY_FILTER, *PCM_NOTIFY_FILTER;