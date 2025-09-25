typedef struct _NDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO {
  union {
    struct {
      UINT32 VirtualSubnetId : 24;
      UINT32 ReservedVsidBits : 8;
      UINT32 Reserved;
    };
    PVOID Value;
  };
} NDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO, *PNDIS_NET_BUFFER_LIST_VIRTUAL_SUBNET_INFO;