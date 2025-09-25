typedef struct _MMC_RESTORE_VIEW {
  DWORD      dwSize;
  MMC_COOKIE cookie;
  LPOLESTR   pViewType;
  long       lViewOptions;
} MMC_RESTORE_VIEW;