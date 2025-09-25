typedef struct _NDIS_NET_BUFFER_LIST_8021Q_INFO {
  union {
    struct {
      UINT32 UserPriority : 3;
      UINT32 CanonicalFormatId : 1;
      UINT32 VlanId : 12;
      UINT32 Reserved : 16;
    } TagHeader;
    struct {
      UINT32 UserPriority : 3;
      UINT32 CanonicalFormatId : 1;
      UINT32 VlanId : 12;
      UINT32 WMMInfo : 4;
      UINT32 Reserved : 12;
    } WLanTagHeader;
    PVOID Value;
  };
} NDIS_NET_BUFFER_LIST_8021Q_INFO, *PNDIS_NET_BUFFER_LIST_8021Q_INFO;