typedef struct _SEC_APPLICATION_PROTOCOL_LIST {
  SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT ProtoNegoExt;
  unsigned short                           ProtocolListSize;
  unsigned char                            ProtocolList[ANYSIZE_ARRAY];
} SEC_APPLICATION_PROTOCOL_LIST, *PSEC_APPLICATION_PROTOCOL_LIST;