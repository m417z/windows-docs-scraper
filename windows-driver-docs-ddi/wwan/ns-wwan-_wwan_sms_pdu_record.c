typedef struct _WWAN_SMS_PDU_RECORD {
  ULONG           MessageIndex;
  WWAN_MSG_STATUS MsgStatus;
  BYTE            Size;
  CHAR            PduData[WWAN_SMS_PDU_HEX_BUF_LEN];
} WWAN_SMS_PDU_RECORD, *PWWAN_SMS_PDU_RECORD;