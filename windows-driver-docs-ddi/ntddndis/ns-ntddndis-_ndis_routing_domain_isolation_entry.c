typedef struct _NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  Flags;
  NDIS_ISOLATION_ID_NAME IsolationIdName;
  union {
    struct {
      UINT32 VirtualSubnetId : 24;
    };
    struct {
      UINT32 VlanId : 12;
    };
    UINT32 IsolationId;
  };
} NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY, *PNDIS_ROUTING_DOMAIN_ISOLATION_ENTRY;