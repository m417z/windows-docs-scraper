BOOL WinUsb_ReadIsochPipe(
  [in]           WINUSB_ISOCH_BUFFER_HANDLE  BufferHandle,
  [in]           ULONG                       Offset,
  [in]           ULONG                       Length,
  [in, out]      PULONG                      FrameNumber,
  [in]           ULONG                       NumberOfPackets,
  [out]          PUSBD_ISO_PACKET_DESCRIPTOR IsoPacketDescriptors,
  [in, optional] LPOVERLAPPED                Overlapped
);