typedef struct {
  IntServServiceHdr Gads_serv_hdr;
  IntServParmHdr    Gads_Ctot_hdr;
  ULONG             Gads_Ctot;
  IntServParmHdr    Gads_Dtot_hdr;
  ULONG             Gads_Dtot;
  IntServParmHdr    Gads_Csum_hdr;
  ULONG             Gads_Csum;
  IntServParmHdr    Gads_Dsum_hdr;
  ULONG             Gads_Dsum;
} Gads_parms_t;