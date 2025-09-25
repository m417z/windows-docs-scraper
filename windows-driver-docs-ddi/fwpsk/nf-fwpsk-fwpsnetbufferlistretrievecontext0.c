NTSTATUS FwpsNetBufferListRetrieveContext0(
  [in, out] NET_BUFFER_LIST *netBufferList,
  [in]      UINT64          contextTag,
  [in]      BOOLEAN         removeContext,
  [in]      UINT32          flags,
  [out]     UINT64          *context
);