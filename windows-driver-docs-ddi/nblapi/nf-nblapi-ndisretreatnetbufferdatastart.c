NDIS_EXPORTED_ROUTINE NDIS_STATUS NdisRetreatNetBufferDataStart(
  [in]           NET_BUFFER              *NetBuffer,
  [in]           ULONG                   DataOffsetDelta,
  [in]           ULONG                   DataBackFill,
  [in, optional] NET_BUFFER_ALLOCATE_MDL *AllocateMdlHandler
);