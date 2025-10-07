typedef struct _DOC_INFO_2 {
  LPTSTR pDocName;
  LPTSTR pOutputFile;
  LPTSTR pDatatype;
  DWORD  dwMode;
  DWORD  JobId;
} DOC_INFO_2, *PDOC_INFO_2;