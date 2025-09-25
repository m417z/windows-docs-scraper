typedef struct _NOTIFICATION_INFO_W2K {
  PMDL          Mdl;
  ULONG         ulOffset;
  ULONG         nLength;
  ULONG         fulNotificationOptions;
  PVOID         Context;
  PADDRESS_FIFO Fifo;
  PVOID         RequestPacket;
  PMDL          ResponseMdl;
  PVOID         *ResponsePacket;
  PULONG        ResponseLength;
  PKEVENT       *ResponseEvent;
} NOTIFICATION_INFO_W2K, *PNOTIFICATION_INFO_W2K;