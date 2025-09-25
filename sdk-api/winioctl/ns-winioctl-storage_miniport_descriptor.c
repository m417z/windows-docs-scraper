typedef struct _STORAGE_MINIPORT_DESCRIPTOR {
  DWORD                 Version;
  DWORD                 Size;
  STORAGE_PORT_CODE_SET Portdriver;
  BOOLEAN               LUNResetSupported;
  BOOLEAN               TargetResetSupported;
  WORD                  IoTimeoutValue;
  BOOLEAN               ExtraIoInfoSupported;
  union {
    struct {
      BYTE LogicalPoFxForDisk : 1;
      BYTE ForwardIo : 1;
      BYTE Reserved : 6;
    } DUMMYSTRUCTNAME;
    BYTE AsBYTE;
  } Flags;
#if ...
  BYTE                  Reserved0[2];
#else
  BYTE                  Reserved0[3];
#endif
  DWORD                 Reserved1;
} STORAGE_MINIPORT_DESCRIPTOR, *PSTORAGE_MINIPORT_DESCRIPTOR;