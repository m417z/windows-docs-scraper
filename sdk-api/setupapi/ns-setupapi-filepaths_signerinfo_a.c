typedef struct _FILEPATHS_SIGNERINFO_A {
  PCSTR Target;
  PCSTR Source;
  UINT  Win32Error;
  DWORD Flags;
  PCSTR DigitalSigner;
  PCSTR Version;
  PCSTR CatalogFile;
} FILEPATHS_SIGNERINFO_A, *PFILEPATHS_SIGNERINFO_A;