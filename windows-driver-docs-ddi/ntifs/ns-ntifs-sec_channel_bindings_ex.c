typedef struct _SEC_CHANNEL_BINDINGS_EX {
  unsigned long magicNumber;
  unsigned long flags;
  unsigned long cbHeaderLength;
  unsigned long cbStructureLength;
  unsigned long dwInitiatorAddrType;
  unsigned long cbInitiatorLength;
  unsigned long dwInitiatorOffset;
  unsigned long dwAcceptorAddrType;
  unsigned long cbAcceptorLength;
  unsigned long dwAcceptorOffset;
  unsigned long cbApplicationDataLength;
  unsigned long dwApplicationDataOffset;
} SEC_CHANNEL_BINDINGS_EX, *PSEC_CHANNEL_BINDINGS_EX;