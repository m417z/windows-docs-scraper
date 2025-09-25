struct _URB_BULK_OR_INTERRUPT_TRANSFER {
  struct _URB_HEADER   Hdr;
  USBD_PIPE_HANDLE     PipeHandle;
  ULONG                TransferFlags;
  ULONG                TransferBufferLength;
  PVOID                TransferBuffer;
  PMDL                 TransferBufferMDL;
  struct _URB          *UrbLink;
  struct _URB_HCD_AREA hca;
};