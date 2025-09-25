typedef struct _NDIS_PM_WAKE_REASON {
  NDIS_OBJECT_HEADER       Header;
  ULONG                    Flags;
  NDIS_PM_WAKE_REASON_TYPE WakeReason;
  ULONG                    InfoBufferOffset;
  ULONG                    InfoBufferSize;
} NDIS_PM_WAKE_REASON, *PNDIS_PM_WAKE_REASON;