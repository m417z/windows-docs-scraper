typedef struct _KERB_BINDING_CACHE_ENTRY_DATA {
  ULONG64        DiscoveryTime;
  UNICODE_STRING RealmName;
  UNICODE_STRING KdcAddress;
  ULONG          AddressType;
  ULONG          Flags;
  ULONG          DcFlags;
  ULONG          CacheFlags;
  UNICODE_STRING KdcName;
} KERB_BINDING_CACHE_ENTRY_DATA, *PKERB_BINDING_CACHE_ENTRY_DATA;