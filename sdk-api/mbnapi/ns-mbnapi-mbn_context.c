typedef struct MBN_CONTEXT {
  ULONG             contextID;
  MBN_CONTEXT_TYPE  contextType;
  BSTR              accessString;
  BSTR              userName;
  BSTR              password;
  MBN_COMPRESSION   compression;
  MBN_AUTH_PROTOCOL authType;
} MBN_CONTEXT;