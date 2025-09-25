typedef struct _NDIS_HYPERVISOR_INFO {
  NDIS_OBJECT_HEADER             Header;
  ULONG                          Flags;
  NDIS_HYPERVISOR_PARTITION_TYPE PartitionType;
} NDIS_HYPERVISOR_INFO, *PNDIS_HYPERVISOR_INFO;