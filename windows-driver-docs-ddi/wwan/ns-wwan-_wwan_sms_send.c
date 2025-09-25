typedef struct _WWAN_SMS_SEND {
  WWAN_SMS_FORMAT SmsFormat;
  union {
    WWAN_SMS_SEND_PDU  Pdu;
    WWAN_SMS_SEND_CDMA Cdma;
  } u;
} WWAN_SMS_SEND, *PWWAN_SMS_SEND;