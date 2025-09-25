typedef struct _KSDEVICE_DESCRIPTOR {
  const KSDEVICE_DISPATCH   *Dispatch;
  ULONG                     FilterDescriptorsCount;
  const KSFILTER_DESCRIPTOR const * * FilterDescriptors;
  ULONG                     Version;
  ULONG                     Flags;
  PVOID                     Alignment;
} KSDEVICE_DESCRIPTOR, *PKSDEVICE_DESCRIPTOR;