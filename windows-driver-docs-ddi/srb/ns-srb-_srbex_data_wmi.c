typedef struct _SRBEX_DATA_WMI {
  SRBEXDATATYPE       Type;
  ULONG               Length;
  UCHAR               WMISubFunction;
  UCHAR               WMIFlags;
  UCHAR               Reserved[2];
  ULONG               Reserved1;
  PVOID POINTER_ALIGN DataPath;
} SRBEX_DATA_WMI, *PSRBEX_DATA_WMI;