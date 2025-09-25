typedef struct _NDIS_OFFLOAD_ENCAPSULATION {
  NDIS_OBJECT_HEADER Header;
  struct {
    ULONG Enabled;
    ULONG EncapsulationType;
    ULONG HeaderSize;
  } IPv4;
  struct {
    ULONG Enabled;
    ULONG EncapsulationType;
    ULONG HeaderSize;
  } IPv6;
} NDIS_OFFLOAD_ENCAPSULATION, *PNDIS_OFFLOAD_ENCAPSULATION;