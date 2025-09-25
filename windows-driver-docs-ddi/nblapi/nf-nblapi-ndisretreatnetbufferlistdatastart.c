NDIS_EXPORTED_ROUTINE NDIS_STATUS NdisRetreatNetBufferListDataStart(
  [in]           NET_BUFFER_LIST         *NetBufferList,
  [in]           ULONG                   DataOffsetDelta,
  [in]           ULONG                   DataBackFill,
  [in, optional] NET_BUFFER_ALLOCATE_MDL *AllocateMdlHandler,
  [in, optional] NET_BUFFER_FREE_MDL     *FreeMdlHandler
);