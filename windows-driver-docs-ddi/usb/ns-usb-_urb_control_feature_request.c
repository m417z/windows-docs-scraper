struct _URB_CONTROL_FEATURE_REQUEST {
  struct _URB_HEADER   Hdr;
  PVOID                Reserved;
  ULONG                Reserved2;
  ULONG                Reserved3;
  PVOID                Reserved4;
  PMDL                 Reserved5;
  struct _URB          *UrbLink;
  struct _URB_HCD_AREA hca;
  USHORT               Reserved0;
  USHORT               FeatureSelector;
  USHORT               Index;
  USHORT               Reserved1;
};