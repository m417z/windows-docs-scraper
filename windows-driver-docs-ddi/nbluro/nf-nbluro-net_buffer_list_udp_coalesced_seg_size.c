#define NET_BUFFER_LIST_UDP_COALESCED_SEG_SIZE(_NBL) \
    (((NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO*) \
        &(_NBL)->NetBufferListInfo[UdpRecvSegCoalesceOffloadInfo])->Receive.SegSize)