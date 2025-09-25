struct _URB_CONTROL_GET_CONFIGURATION_REQUEST {
  struct _URB_HEADER   Hdr;
  PVOID                Reserved;
  ULONG                Reserved0;
  ULONG                TransferBufferLength;
  PVOID                TransferBuffer;
  PMDL                 TransferBufferMDL;
  struct _URB          *UrbLink;
  struct _URB_HCD_AREA hca;
  UCHAR                Reserved1[8];
};