typedef struct JOBOBJECT_IO_RATE_CONTROL_INFORMATION {
  LONG64 MaxIops;
  LONG64 MaxBandwidth;
  LONG64 ReservationIops;
  PCWSTR VolumeName;
  ULONG  BaseIoSize;
  ULONG  ControlFlags;
} JOBOBJECT_IO_RATE_CONTROL_INFORMATION;