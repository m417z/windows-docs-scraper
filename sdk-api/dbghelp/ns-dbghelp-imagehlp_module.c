typedef struct _IMAGEHLP_MODULE {
  DWORD    SizeOfStruct;
  DWORD    BaseOfImage;
  DWORD    ImageSize;
  DWORD    TimeDateStamp;
  DWORD    CheckSum;
  DWORD    NumSyms;
  SYM_TYPE SymType;
  CHAR     ModuleName[32];
  CHAR     ImageName[256];
  CHAR     LoadedImageName[256];
} IMAGEHLP_MODULE, *PIMAGEHLP_MODULE;