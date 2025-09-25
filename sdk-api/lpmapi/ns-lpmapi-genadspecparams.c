typedef struct {
  IntServServiceHdr gen_parm_hdr;
  IntServParmHdr    gen_parm_hopcnt_hdr;
  ULONG             gen_parm_hopcnt;
  IntServParmHdr    gen_parm_pathbw_hdr;
  FLOAT             gen_parm_path_bw;
  IntServParmHdr    gen_parm_minlat_hdr;
  ULONG             gen_parm_min_latency;
  IntServParmHdr    gen_parm_compmtu_hdr;
  ULONG             gen_parm_composed_MTU;
} GenAdspecParams;