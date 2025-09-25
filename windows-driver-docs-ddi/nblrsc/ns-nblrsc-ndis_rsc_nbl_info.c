typedef union _NDIS_RSC_NBL_INFO {
  struct {
    USHORT CoalescedSegCount;
    USHORT DupAckCount;
  } Info;
  PVOID  Value;
} NDIS_RSC_NBL_INFO, *PNDIS_RSC_NBL_INFO;