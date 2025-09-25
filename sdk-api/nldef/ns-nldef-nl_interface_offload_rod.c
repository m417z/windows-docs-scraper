typedef struct _NL_INTERFACE_OFFLOAD_ROD {
  BOOLEAN NlChecksumSupported : 1;
  BOOLEAN NlOptionsSupported : 1;
  BOOLEAN TlDatagramChecksumSupported : 1;
  BOOLEAN TlStreamChecksumSupported : 1;
  BOOLEAN TlStreamOptionsSupported : 1;
  BOOLEAN FastPathCompatible : 1;
  BOOLEAN TlLargeSendOffloadSupported : 1;
  BOOLEAN TlGiantSendOffloadSupported : 1;
} NL_INTERFACE_OFFLOAD_ROD, *PNL_INTERFACE_OFFLOAD_ROD;