typedef struct _GETSETBUSDATA {
  ULONG BusDataType;
  ULONG BusNumber;
  ULONG SlotNumber;
  PVOID Buffer;
  ULONG Offset;
  ULONG Length;
} BUSDATA, *PBUSDATA;