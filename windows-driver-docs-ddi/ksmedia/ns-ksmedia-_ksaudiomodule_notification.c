typedef struct _KSAUDIOMODULE_NOTIFICATION {
  union {
    struct {
      GUID  DeviceId;
      GUID  ClassId;
      ULONG InstanceId;
      ULONG Reserved;
    } ProviderId;
    LONGLONG Alignment;
  };
} KSAUDIOMODULE_NOTIFICATION, *PKSAUDIOMODULE_NOTIFICATION;