typedef struct _NET_DMA_PNP_NOTIFICATION {
  ULONG                         StructureRevision;
  ULONG                         StructureSize;
  NET_DMA_PNP_NOTIFICATION_CODE NotificationCode;
  PVOID                         Buffer;
  ULONG                         BufferLength;
} NET_DMA_PNP_NOTIFICATION, *PNET_DMA_PNP_NOTIFICATION;