DXGKDDI_DISPATCH_IO_REQUEST DxgkddiDispatchIoRequest;

NTSTATUS DxgkddiDispatchIoRequest(
  [in] IN_CONST_PVOID MiniportDeviceContext,
  [in] IN_ULONG VidPnSourceId,
  [in] IN_PVIDEO_REQUEST_PACKET VideoRequestPacket
)
{...}