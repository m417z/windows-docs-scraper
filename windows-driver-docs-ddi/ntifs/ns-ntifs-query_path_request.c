typedef struct _QUERY_PATH_REQUEST {
  ULONG                PathNameLength;
  PIO_SECURITY_CONTEXT SecurityContext;
  WCHAR                FilePathName[1];
} QUERY_PATH_REQUEST, *PQUERY_PATH_REQUEST;