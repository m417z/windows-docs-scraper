typedef struct _KERB_RETRIEVE_TKT_REQUEST {
  KERB_PROTOCOL_MESSAGE_TYPE MessageType;
  LUID                       LogonId;
  UNICODE_STRING             TargetName;
  ULONG                      TicketFlags;
  ULONG                      CacheOptions;
  LONG                       EncryptionType;
  SecHandle                  CredentialsHandle;
} KERB_RETRIEVE_TKT_REQUEST, *PKERB_RETRIEVE_TKT_REQUEST;