typedef struct _NDIS_WWAN_SMS_SEND_STATUS {
  NDIS_OBJECT_HEADER Header;
  WWAN_STATUS        uStatus;
  ULONG              MessageReference;
} NDIS_WWAN_SMS_SEND_STATUS, *PNDIS_WWAN_SMS_SEND_STATUS;