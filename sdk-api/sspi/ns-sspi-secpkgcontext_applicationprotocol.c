typedef struct _SecPkgContext_ApplicationProtocol {
  SEC_APPLICATION_PROTOCOL_NEGOTIATION_STATUS ProtoNegoStatus;
  SEC_APPLICATION_PROTOCOL_NEGOTIATION_EXT    ProtoNegoExt;
  unsigned char                               ProtocolIdSize;
  unsigned char                               ProtocolId[MAX_PROTOCOL_ID_SIZE];
} SecPkgContext_ApplicationProtocol, *PSecPkgContext_ApplicationProtocol;