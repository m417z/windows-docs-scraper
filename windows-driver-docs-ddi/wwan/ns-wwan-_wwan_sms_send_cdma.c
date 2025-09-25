typedef struct _WWAN_SMS_SEND_CDMA {
  WWAN_SMS_CDMA_ENCODING EncodingId;
  WWAN_SMS_CDMA_LANG     LanguageId;
  CHAR                   Address[WWAN_SMS_CDMA_ADDR_MAX_LEN];
  USHORT                 SizeInBytes;
  BYTE                   SizeInCharacters;
  BYTE                   EncodedMsg[WWAN_SMS_CDMA_MAX_BUF_LEN];
} WWAN_SMS_SEND_CDMA, *PWWAN_SMS_SEND_CDMA;