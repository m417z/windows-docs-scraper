NDIS_EXPORTED_ROUTINE VOID NdisAdvanceNetBufferListDataStart(
  [in] NET_BUFFER_LIST     *NetBufferList,
  [in] ULONG               DataOffsetDelta,
  [in] BOOLEAN             FreeMdl,
       NET_BUFFER_FREE_MDL *FreeMdlMdlHandler
);