typedef struct _MINIDUMP_MODULE_CALLBACK {
  PWCHAR           FullPath;
  ULONG64          BaseOfImage;
  ULONG            SizeOfImage;
  ULONG            CheckSum;
  ULONG            TimeDateStamp;
  VS_FIXEDFILEINFO VersionInfo;
  PVOID            CvRecord;
  ULONG            SizeOfCvRecord;
  PVOID            MiscRecord;
  ULONG            SizeOfMiscRecord;
} MINIDUMP_MODULE_CALLBACK, *PMINIDUMP_MODULE_CALLBACK;