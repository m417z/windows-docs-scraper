typedef struct _KERB_EXTERNAL_TICKET {
  PKERB_EXTERNAL_NAME ServiceName;
  PKERB_EXTERNAL_NAME TargetName;
  PKERB_EXTERNAL_NAME ClientName;
  UNICODE_STRING      DomainName;
  UNICODE_STRING      TargetDomainName;
  UNICODE_STRING      AltTargetDomainName;
  KERB_CRYPTO_KEY     SessionKey;
  ULONG               TicketFlags;
  ULONG               Flags;
  LARGE_INTEGER       KeyExpirationTime;
  LARGE_INTEGER       StartTime;
  LARGE_INTEGER       EndTime;
  LARGE_INTEGER       RenewUntil;
  LARGE_INTEGER       TimeSkew;
  ULONG               EncodedTicketSize;
  PUCHAR              EncodedTicket;
} KERB_EXTERNAL_TICKET, *PKERB_EXTERNAL_TICKET;