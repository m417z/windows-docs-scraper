DWORD PXEAPI PxeProviderRecvRequest(
  _In_  HANDLE          hClientRequest,
  _In_  PVOID           pPacket,
  _In_  ULONG           uPacketLen,
  _In_  PXE_ADDRESS     *pLocalAddress,
  _In_  PXE_ADDRESS     *pRemoteAddress,
  _Out_ PXE_BOOT_ACTION pAction,
  _In_  PVOID           pContext
);