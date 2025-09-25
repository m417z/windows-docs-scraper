typedef struct _MODE_PAGE_SUBPAGE_HEADER {
  UCHAR PageCode : 6;
  UCHAR SubPageFormat : 1;
  UCHAR PageSavable : 1;
  UCHAR SubPageCode;
  UCHAR PageLength[2];
} MODE_PAGE_SUBPAGE_HEADER, *PMODE_PAGE_SUBPAGE_HEADER;