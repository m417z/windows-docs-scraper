typedef struct DOT11_EXTSTA_SEND_CONTEXT {
  NDIS_OBJECT_HEADER Header;
  USHORT             usExemptionActionType;
  ULONG              uPhyId;
  ULONG              uDelayedSleepValue;
  PVOID              pvMediaSpecificInfo;
  ULONG              uSendFlags;
} DOT11_EXTSTA_SEND_CONTEXT, *PDOT11_EXTSTA_SEND_CONTEXT;