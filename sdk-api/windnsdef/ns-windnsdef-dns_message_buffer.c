typedef struct _DNS_MESSAGE_BUFFER {
  DNS_HEADER MessageHead;
  CHAR       MessageBody[1];
} DNS_MESSAGE_BUFFER, *PDNS_MESSAGE_BUFFER;