typedef struct _KERB_ADD_BINDING_CACHE_ENTRY_EX_REQUEST {
  KERB_PROTOCOL_MESSAGE_TYPE MessageType;
  UNICODE_STRING             RealmName;
  UNICODE_STRING             KdcAddress;
  ULONG                      AddressType;
  ULONG                      DcFlags;
} KERB_ADD_BINDING_CACHE_ENTRY_EX_REQUEST, *PKERB_ADD_BINDING_CACHE_ENTRY_EX_REQUEST;