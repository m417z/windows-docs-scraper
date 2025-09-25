struct _URB_CONTROL_TRANSFER_EX {
  struct _URB_HEADER   Hdr;
  USBD_PIPE_HANDLE     PipeHandle;
  ULONG                TransferFlags;
  ULONG                TransferBufferLength;
  PVOID                TransferBuffer;
  PMDL                 TransferBufferMDL;
  ULONG                Timeout;
  ULONG                Pad;
  struct _URB_HCD_AREA hca;
  UCHAR                SetupPacket[8];
};