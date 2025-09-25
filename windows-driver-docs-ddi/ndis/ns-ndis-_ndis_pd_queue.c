typedef struct _NDIS_PD_QUEUE {
  NDIS_OBJECT_HEADER           Header;
  ULONG                        Flags;
  const NDIS_PD_QUEUE_DISPATCH *Dispatch;
  PVOID                        PDPlatformReserved[2];
  PVOID                        PDClientReserved[2];
} NDIS_PD_QUEUE;