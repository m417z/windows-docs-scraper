typedef struct _BCryptBufferDesc {
  ULONG         ulVersion;
  ULONG         cBuffers;
  PBCryptBuffer pBuffers;
} BCryptBufferDesc, *PBCryptBufferDesc;