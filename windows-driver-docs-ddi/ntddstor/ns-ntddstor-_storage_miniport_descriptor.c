typedef struct _STORAGE_MINIPORT_DESCRIPTOR {
  ULONG                 Version;
  ULONG                 Size;
  STORAGE_PORT_CODE_SET Portdriver;
  BOOLEAN               LUNResetSupported;
  BOOLEAN               TargetResetSupported;
  USHORT                IoTimeoutValue;
  BOOLEAN               ExtraIoInfoSupported;
  union {
    struct {
      UCHAR LogicalPoFxForDisk : 1;
      UCHAR ForwardIo : 1;
      UCHAR Reserved : 6;
    } DUMMYSTRUCTNAME;
    UCHAR AsUCHAR;
  } Flags;
#if ...
  UCHAR                 Reserved0[2];
#else
  UCHAR                 Reserved0[3];
#endif
  ULONG                 Reserved1;
} STORAGE_MINIPORT_DESCRIPTOR, *PSTORAGE_MINIPORT_DESCRIPTOR;