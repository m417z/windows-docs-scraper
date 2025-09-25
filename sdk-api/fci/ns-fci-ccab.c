typedef struct {
  ULONG  cb;
  ULONG  cbFolderThresh;
  UINT   cbReserveCFHeader;
  UINT   cbReserveCFFolder;
  UINT   cbReserveCFData;
  int    iCab;
  int    iDisk;
  int    fFailOnIncompressible;
  USHORT setID;
  char   szDisk[CB_MAX_DISK_NAME];
  char   szCab[CB_MAX_CABINET_NAME];
  char   szCabPath[CB_MAX_CAB_PATH];
} CCAB;