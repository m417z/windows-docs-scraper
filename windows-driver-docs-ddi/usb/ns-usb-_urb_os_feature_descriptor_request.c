struct _URB_OS_FEATURE_DESCRIPTOR_REQUEST {
  struct _URB_HEADER   Hdr;
  PVOID                Reserved;
  ULONG                Reserved0;
  ULONG                TransferBufferLength;
  PVOID                TransferBuffer;
  PMDL                 TransferBufferMDL;
  struct _URB          *UrbLink;
  struct _URB_HCD_AREA hca;
  UCHAR                Recipient : 5;
  UCHAR                Reserved1 : 3;
  UCHAR                Reserved2;
  UCHAR                InterfaceNumber;
  UCHAR                MS_PageIndex;
  USHORT               MS_FeatureDescriptorIndex;
  USHORT               Reserved3;
};