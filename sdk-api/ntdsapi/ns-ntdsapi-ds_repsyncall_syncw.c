typedef struct {
  LPWSTR pszSrcId;
  LPWSTR pszDstId;
  LPWSTR pszNC;
  GUID   *pguidSrc;
  GUID   *pguidDst;
} DS_REPSYNCALL_SYNCW, *PDS_REPSYNCALL_SYNCW;