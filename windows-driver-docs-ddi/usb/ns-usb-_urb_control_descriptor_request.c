struct _URB_CONTROL_DESCRIPTOR_REQUEST {
  struct _URB_HEADER   Hdr;
  PVOID                Reserved;
  ULONG                Reserved0;
  ULONG                TransferBufferLength;
  PVOID                TransferBuffer;
  PMDL                 TransferBufferMDL;
  struct _URB          *UrbLink;
  struct _URB_HCD_AREA hca;
  USHORT               Reserved1;
  UCHAR                Index;
  UCHAR                DescriptorType;
  USHORT               LanguageId;
  USHORT               Reserved2;
};