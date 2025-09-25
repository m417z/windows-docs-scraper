typedef struct TF_PERSISTENT_PROPERTY_HEADER_ACP {
  GUID  guidType;
  LONG  ichStart;
  LONG  cch;
  ULONG cb;
  DWORD dwPrivate;
  CLSID clsidTIP;
} TF_PERSISTENT_PROPERTY_HEADER_ACP;