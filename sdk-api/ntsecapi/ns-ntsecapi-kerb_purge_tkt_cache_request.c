typedef struct _KERB_PURGE_TKT_CACHE_REQUEST {
  KERB_PROTOCOL_MESSAGE_TYPE MessageType;
  LUID                       LogonId;
  UNICODE_STRING             ServerName;
  UNICODE_STRING             RealmName;
} KERB_PURGE_TKT_CACHE_REQUEST, *PKERB_PURGE_TKT_CACHE_REQUEST;