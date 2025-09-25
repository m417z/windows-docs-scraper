BOOL WinUsb_ReadIsochPipeAsap(
  [in]           WINUSB_ISOCH_BUFFER_HANDLE  BufferHandle,
  [in]           ULONG                       Offset,
  [in]           ULONG                       Length,
  [in]           BOOL                        ContinueStream,
  [in]           ULONG                       NumberOfPackets,
                 PUSBD_ISO_PACKET_DESCRIPTOR IsoPacketDescriptors,
  [in, optional] LPOVERLAPPED                Overlapped
);