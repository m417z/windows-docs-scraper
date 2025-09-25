typedef struct _SEC_SESSION_TICKET {
  unsigned short SessionTicketSize;
  unsigned char  SessionTicket[ANYSIZE_ARRAY];
} SEC_SESSION_TICKET, *PSEC_SESSION_TICKET;