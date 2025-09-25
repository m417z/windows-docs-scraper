typedef struct _WWAN_SMS_CDMA_RECORD {
  ULONG                  MessageIndex;
  WWAN_MSG_STATUS        MsgStatus;
  CHAR                   Address[WWAN_SMS_CDMA_ADDR_MAX_LEN];
  CHAR                   ScTimeStamp[WWAN_SMS_CDMA_TIMESTAMP_MAX_LEN];
  WWAN_SMS_CDMA_ENCODING EncodingId;
  WWAN_SMS_CDMA_LANG     LanguageId;
  USHORT                 SizeInBytes;
  BYTE                   SizeInCharacters;
  BYTE                   EncodedMsg[WWAN_SMS_CDMA_MAX_BUF_LEN];
} WWAN_SMS_CDMA_RECORD, *PWWAN_SMS_CDMA_RECORD;