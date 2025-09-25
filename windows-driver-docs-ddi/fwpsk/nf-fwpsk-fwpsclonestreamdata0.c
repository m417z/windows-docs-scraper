NTSTATUS FwpsCloneStreamData0(
  [in, out]      FWPS_STREAM_DATA0 *calloutStreamData,
  [in, optional] NDIS_HANDLE       netBufferListPoolHandle,
  [in, optional] NDIS_HANDLE       netBufferPoolHandle,
  [in]           ULONG             allocateCloneFlags,
  [out]          NET_BUFFER_LIST   **netBufferListChain
);