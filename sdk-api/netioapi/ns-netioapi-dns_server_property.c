typedef struct _DNS_SERVER_PROPERTY {
  ULONG                     Version;
  ULONG                     ServerIndex;
  DNS_SERVER_PROPERTY_TYPE  Type;
#if ...
  DNS_SERVER_PROPERTY_TYPES Property;
#else
  DNS_SERVER_PROPERTY_TYPES Property;
#endif
} DNS_SERVER_PROPERTY;