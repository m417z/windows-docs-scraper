typedef struct _NDIS_TIMESTAMP_CAPABILITIES {
  NDIS_OBJECT_HEADER              Header;
  ULONG64                         HardwareClockFrequencyHz;
  BOOLEAN                         CrossTimestamp;
  ULONG64                         Reserved1;
  ULONG64                         Reserved2;
  NDIS_TIMESTAMP_CAPABILITY_FLAGS TimestampFlags;
} NDIS_TIMESTAMP_CAPABILITIES, *PNDIS_TIMESTAMP_CAPABILITIES;