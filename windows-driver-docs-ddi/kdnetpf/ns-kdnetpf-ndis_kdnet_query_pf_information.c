typedef struct _NDIS_KDNET_QUERY_PF_INFORMATION {
  NDIS_OBJECT_HEADER Header;
  NDIS_KDNET_BDF     Bdf;
  UCHAR              NetworkAdddress[6];
  ULONG              UsageTag;
  ULONG              MaximumNumberOfSupportedPfs;
  ULONG              DeviceId;
} NDIS_KDNET_QUERY_PF_INFORMATION, *PNDIS_KDNET_QUERY_PF_INFORMATION;