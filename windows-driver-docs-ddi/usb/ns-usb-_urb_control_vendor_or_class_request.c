struct _URB_CONTROL_VENDOR_OR_CLASS_REQUEST {
  struct _URB_HEADER   Hdr;
  PVOID                Reserved;
  ULONG                TransferFlags;
  ULONG                TransferBufferLength;
  PVOID                TransferBuffer;
  PMDL                 TransferBufferMDL;
  struct _URB          *UrbLink;
  struct _URB_HCD_AREA hca;
  UCHAR                RequestTypeReservedBits;
  UCHAR                Request;
  USHORT               Value;
  USHORT               Index;
  USHORT               Reserved1;
};