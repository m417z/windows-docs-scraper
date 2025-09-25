typedef struct _MSFC_VirtualFibrePortAttributes {
  ULONG  Status;
  ULONG  FCId;
  USHORT VirtualName[64];
  UCHAR  Tag[16];
  UCHAR  WWPN[8];
  UCHAR  WWNN[8];
  UCHAR  FabricWWN[8];
} MSFC_VirtualFibrePortAttributes, *PMSFC_VirtualFibrePortAttributes;