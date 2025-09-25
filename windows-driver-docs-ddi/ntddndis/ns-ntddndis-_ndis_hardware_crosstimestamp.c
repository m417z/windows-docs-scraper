typedef struct _NDIS_HARDWARE_CROSSTIMESTAMP {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG64            SystemTimestamp1;
  ULONG64            HardwareClockTimestamp;
  ULONG64            SystemTimestamp2;
} NDIS_HARDWARE_CROSSTIMESTAMP, *PNDIS_HARDWARE_CROSSTIMESTAMP;