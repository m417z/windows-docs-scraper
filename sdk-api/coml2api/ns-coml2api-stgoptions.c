typedef struct tagSTGOPTIONS {
  USHORT      usVersion;
  USHORT      reserved;
  ULONG       ulSectorSize;
  const WCHAR *pwcsTemplateFile;
} STGOPTIONS;