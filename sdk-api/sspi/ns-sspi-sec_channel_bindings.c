typedef struct _SEC_CHANNEL_BINDINGS {
  unsigned long dwInitiatorAddrType;
  unsigned long cbInitiatorLength;
  unsigned long dwInitiatorOffset;
  unsigned long dwAcceptorAddrType;
  unsigned long cbAcceptorLength;
  unsigned long dwAcceptorOffset;
  unsigned long cbApplicationDataLength;
  unsigned long dwApplicationDataOffset;
} SEC_CHANNEL_BINDINGS, *PSEC_CHANNEL_BINDINGS;