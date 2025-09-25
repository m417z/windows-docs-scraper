NTSTATUS FwpsReassembleForwardFragmentGroup0(
  [in]           ADDRESS_FAMILY  addressFamily,
  [in, out]      NET_BUFFER_LIST *fragmentGroupNblChain,
  [in, optional] NDIS_HANDLE     netBufferAndNetBufferListPoolHandle,
  [in]           ULONG           dataBackFill,
  [in]           ULONG           flags,
  [out]          NET_BUFFER_LIST **reassembledNbl
);