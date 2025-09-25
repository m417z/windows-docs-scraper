typedef struct _KERB_TICKET_LOGON {
  KERB_LOGON_SUBMIT_TYPE MessageType;
  ULONG                  Flags;
  ULONG                  ServiceTicketLength;
  ULONG                  TicketGrantingTicketLength;
  PUCHAR                 ServiceTicket;
  PUCHAR                 TicketGrantingTicket;
} KERB_TICKET_LOGON, *PKERB_TICKET_LOGON;