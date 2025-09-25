typedef struct _FILEPATHS_SIGNERINFO_W {
  PCWSTR Target;
  PCWSTR Source;
  UINT   Win32Error;
  DWORD  Flags;
  PCWSTR DigitalSigner;
  PCWSTR Version;
  PCWSTR CatalogFile;
} FILEPATHS_SIGNERINFO_W, *PFILEPATHS_SIGNERINFO_W;