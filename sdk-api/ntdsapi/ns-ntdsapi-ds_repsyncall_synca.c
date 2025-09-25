typedef struct {
  LPSTR pszSrcId;
  LPSTR pszDstId;
  LPSTR pszNC;
  GUID  *pguidSrc;
  GUID  *pguidDst;
} DS_REPSYNCALL_SYNCA, *PDS_REPSYNCALL_SYNCA;