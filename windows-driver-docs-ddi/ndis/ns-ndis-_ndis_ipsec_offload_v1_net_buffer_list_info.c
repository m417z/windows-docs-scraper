typedef struct _NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO {
  union {
    struct {
      NDIS_HANDLE OffloadHandle;
    } Transmit;
    struct {
      USHORT SaDeleteReq : 1;
      USHORT CryptoDone : 1;
      USHORT NextCryptoDone : 1;
      USHORT Pad : 13;
      USHORT CryptoStatus;
    } Receive;
  };
} NDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO, *PNDIS_IPSEC_OFFLOAD_V1_NET_BUFFER_LIST_INFO;