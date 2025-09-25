typedef struct _NOTIFICATION_INFO_WXP {
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
  RCODE         ResponseCode;
} NOTIFICATION_INFO_WXP, *PNOTIFICATION_INFO_WXP;