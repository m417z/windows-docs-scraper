typedef struct _KERB_ADD_CREDENTIALS_REQUEST {
  KERB_PROTOCOL_MESSAGE_TYPE MessageType;
  UNICODE_STRING             UserName;
  UNICODE_STRING             DomainName;
  UNICODE_STRING             Password;
  LUID                       LogonId;
  ULONG                      Flags;
} KERB_ADD_CREDENTIALS_REQUEST, *PKERB_ADD_CREDENTIALS_REQUEST;