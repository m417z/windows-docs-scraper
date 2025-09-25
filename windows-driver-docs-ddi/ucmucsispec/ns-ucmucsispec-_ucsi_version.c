typedef union _UCSI_VERSION {
  UINT16 AsUInt16;
  struct {
    UINT16 SubMinorVersion : 4;
    UINT16 MinorVersion : 4;
    UINT16 MajorVersion : 8;
  };
} UCSI_VERSION, *PUCSI_VERSION;