typedef struct _NDIS_PM_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  ULONG              EnabledWoLPacketPatterns;
  ULONG              EnabledProtocolOffloads;
  ULONG              WakeUpFlags;
  ULONG              MediaSpecificWakeUpEvents;
} NDIS_PM_PARAMETERS, *PNDIS_PM_PARAMETERS;