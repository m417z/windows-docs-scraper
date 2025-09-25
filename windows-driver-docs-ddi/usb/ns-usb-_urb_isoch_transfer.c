struct _URB_ISOCH_TRANSFER {
  struct _URB_HEADER         Hdr;
  USBD_PIPE_HANDLE           PipeHandle;
  ULONG                      TransferFlags;
  ULONG                      TransferBufferLength;
  PVOID                      TransferBuffer;
  PMDL                       TransferBufferMDL;
  struct _URB                *UrbLink;
  struct _URB_HCD_AREA       hca;
  ULONG                      StartFrame;
  ULONG                      NumberOfPackets;
  ULONG                      ErrorCount;
  USBD_ISO_PACKET_DESCRIPTOR IsoPacket[1];
};