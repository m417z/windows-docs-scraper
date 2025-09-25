NDIS_EXPORTED_ROUTINE VOID NdisAdvanceNetBufferDataStart(
  [in]           NET_BUFFER          *NetBuffer,
  [in]           ULONG               DataOffsetDelta,
  [in]           BOOLEAN             FreeMdl,
  [in, optional] NET_BUFFER_FREE_MDL *FreeMdlHandler
);