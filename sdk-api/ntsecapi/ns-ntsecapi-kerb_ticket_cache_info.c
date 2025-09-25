typedef struct _KERB_TICKET_CACHE_INFO {
  UNICODE_STRING ServerName;
  UNICODE_STRING RealmName;
  LARGE_INTEGER  StartTime;
  LARGE_INTEGER  EndTime;
  LARGE_INTEGER  RenewTime;
  LONG           EncryptionType;
  ULONG          TicketFlags;
} KERB_TICKET_CACHE_INFO, *PKERB_TICKET_CACHE_INFO;