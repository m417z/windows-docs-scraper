typedef struct tagRPCOLEMESSAGE {
  void          *reserved1;
  RPCOLEDATAREP dataRepresentation;
  void          *Buffer;
  ULONG         cbBuffer;
  ULONG         iMethod;
  void          *reserved2[5];
  ULONG         rpcFlags;
} RPCOLEMESSAGE;