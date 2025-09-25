typedef union _WHEA_REVISION {
  struct {
    UCHAR MinorRevision;
    UCHAR MajorRevision;
  } DUMMYSTRUCTNAME;
  USHORT AsUSHORT;
} WHEA_REVISION, *PWHEA_REVISION;