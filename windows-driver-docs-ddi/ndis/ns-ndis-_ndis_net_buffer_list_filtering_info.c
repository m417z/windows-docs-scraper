typedef struct _NDIS_NET_BUFFER_LIST_FILTERING_INFO {
  union {
    struct {
      USHORT FilterId;
      union {
        USHORT QueueId;
        USHORT VPortId;
      } QueueVPortInfo;
    } FilteringInfo;
    PVOID Value;
  };
} NDIS_NET_BUFFER_LIST_FILTERING_INFO, *PNDIS_NET_BUFFER_LIST_FILTERING_INFO;