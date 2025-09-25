NTSTATUS FwpsAllocateNetBufferAndNetBufferList0(
  [in]           NDIS_HANDLE     poolHandle,
  [in]           USHORT          contextSize,
  [in]           USHORT          contextBackFill,
  [in, optional] MDL             *mdlChain,
  [in]           ULONG           dataOffset,
  [in]           SIZE_T          dataLength,
  [out]          NET_BUFFER_LIST **netBufferList
);