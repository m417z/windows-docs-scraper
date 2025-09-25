typedef struct SMHBA_LibraryAttributes {
  char   LibPath[256];
  char   VName[256];
  char   VVersion[256];
  struct {
    int tm_mday;
    int tm_mon;
    int tm_year;
  } build_date;
} SMHBA_LIBRARYATTRIBUTES, *PSMHBA_LIBRARYATTRIBUTES;