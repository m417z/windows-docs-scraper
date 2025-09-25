typedef enum _NDIS_FRAME_HEADER {
  NdisFrameHeaderUndefined,
  NdisFrameHeaderMac,
  NdisFrameHeaderArp,
  NdisFrameHeaderIPv4,
  NdisFrameHeaderIPv6,
  NdisFrameHeaderUdp,
  NdisFrameHeaderMaximum
} NDIS_FRAME_HEADER, *PNDIS_FRAME_HEADER;