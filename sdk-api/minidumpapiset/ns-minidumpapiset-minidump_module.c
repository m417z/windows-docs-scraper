typedef struct _MINIDUMP_MODULE {
  ULONG64                      BaseOfImage;
  ULONG32                      SizeOfImage;
  ULONG32                      CheckSum;
  ULONG32                      TimeDateStamp;
  RVA                          ModuleNameRva;
  VS_FIXEDFILEINFO             VersionInfo;
  MINIDUMP_LOCATION_DESCRIPTOR CvRecord;
  MINIDUMP_LOCATION_DESCRIPTOR MiscRecord;
  ULONG64                      Reserved0;
  ULONG64                      Reserved1;
} MINIDUMP_MODULE, *PMINIDUMP_MODULE;