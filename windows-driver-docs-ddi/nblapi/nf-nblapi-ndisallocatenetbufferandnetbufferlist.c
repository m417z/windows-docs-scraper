NDIS_EXPORTED_ROUTINE NET_BUFFER_LIST * NdisAllocateNetBufferAndNetBufferList(
  [in]           NDIS_HANDLE          PoolHandle,
  [in]           USHORT               ContextSize,
  [in]           USHORT               ContextBackFill,
  [in, optional] __drv_aliasesMem MDL *MdlChain,
  [in]           ULONG                DataOffset,
  [in]           SIZE_T               DataLength
);