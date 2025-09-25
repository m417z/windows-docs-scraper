typedef struct {
  ULONG Size;
  ULONG Version;
  ULONG NumCrumbs;
  union {
    GNSS_BREADCRUMB_V1 v1[50];
  };
} GNSS_BREADCRUMB_LIST, *PGNSS_BREADCRUMB_LIST;