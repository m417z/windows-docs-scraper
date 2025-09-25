typedef struct _NDIS_IPSEC_OFFLOAD_V1 {
  struct {
    ULONG Encapsulation;
    ULONG AhEspCombined;
    ULONG TransportTunnelCombined;
    ULONG IPv4Options;
    ULONG Flags;
  } Supported;
  struct {
    ULONG Md5 : 2;
    ULONG Sha_1 : 2;
    ULONG Transport : 2;
    ULONG Tunnel : 2;
    ULONG Send : 2;
    ULONG Receive : 2;
  } IPv4AH;
  struct {
    ULONG Des : 2;
    ULONG Reserved : 2;
    ULONG TripleDes : 2;
    ULONG NullEsp : 2;
    ULONG Transport : 2;
    ULONG Tunnel : 2;
    ULONG Send : 2;
    ULONG Receive : 2;
  } IPv4ESP;
} NDIS_IPSEC_OFFLOAD_V1, *PNDIS_IPSEC_OFFLOAD_V1;