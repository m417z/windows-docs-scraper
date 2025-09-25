typedef struct HBA_LibraryAttributes {
  HBA_BOOLEAN final;
  char        LibPath[256];
  char        VName[256];
  char        VVersion[256];
  struct tm   build_date;
} HBA_LIBRARYATTRIBUTES, *PHBA_LIBRARYATTRIBUTES;