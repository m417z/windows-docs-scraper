typedef struct _EMULATOR_ACCESS_ENTRY {
  ULONG                     BasePort;
  ULONG                     NumConsecutivePorts;
  EMULATOR_PORT_ACCESS_TYPE AccessType;
  UCHAR                     AccessMode;
  UCHAR                     StringSupport;
  PVOID                     Routine;
} EMULATOR_ACCESS_ENTRY, *PEMULATOR_ACCESS_ENTRY;