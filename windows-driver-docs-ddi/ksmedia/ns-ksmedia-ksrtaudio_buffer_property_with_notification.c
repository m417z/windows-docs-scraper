typedef struct {
  KSPROPERTY Property;
  PVOID      BaseAddress;
  ULONG      RequestedBufferSize;
  ULONG      NotificationCount;
} KSRTAUDIO_BUFFER_PROPERTY_WITH_NOTIFICATION, *PKSRTAUDIO_BUFFER_PROPERTY_WITH_NOTIFICATION;