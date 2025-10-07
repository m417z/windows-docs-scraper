typedef struct {
  KSPROPERTY Property;
  PVOID      BaseAddress;
  ULONG      RequestedBufferSize;
} KSRTAUDIO_BUFFER_PROPERTY, *PKSRTAUDIO_BUFFER_PROPERTY;