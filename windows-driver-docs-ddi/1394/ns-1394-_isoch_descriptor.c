typedef struct _ISOCH_DESCRIPTOR {
  ULONG                         fulFlags;
  PMDL                          Mdl;
  ULONG                         ulLength;
  ULONG                         nMaxBytesPerFrame;
  ULONG                         ulSynch;
  ULONG                         ulTag;
  CYCLE_TIME                    CycleTime;
  PBUS_ISOCH_DESCRIPTOR_ROUTINE Callback;
  PVOID                         Context1;
  PVOID                         Context2;
  NTSTATUS                      status;
  ULONG_PTR                     DeviceReserved[8];
  ULONG_PTR                     BusReserved[8];
  ULONG_PTR                     PortReserved[16];
} ISOCH_DESCRIPTOR, *PISOCH_DESCRIPTOR;