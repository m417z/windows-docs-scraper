typedef struct _CSV_QUERY_MDS_PATH {
  DWORD MdsNodeId;
  DWORD DsNodeId;
  DWORD PathLength;
  WCHAR Path[1];
} CSV_QUERY_MDS_PATH, *PCSV_QUERY_MDS_PATH;