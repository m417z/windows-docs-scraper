typedef struct _KERB_SMART_CARD_LOGON {
  KERB_LOGON_SUBMIT_TYPE MessageType;
  UNICODE_STRING         Pin;
  ULONG                  CspDataLength;
  PUCHAR                 CspData;
} KERB_SMART_CARD_LOGON, *PKERB_SMART_CARD_LOGON;