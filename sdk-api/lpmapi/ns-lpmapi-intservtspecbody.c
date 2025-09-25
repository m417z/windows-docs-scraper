typedef struct {
  IntServMainHdr st_mh;
  union {
    GenTspec  gen_stspec;
    QualTspec qual_stspec;
  } tspec_u;
} IntServTspecBody;