typedef struct {
  IntServServiceHdr Guar_serv_hdr;
  IntServParmHdr    Guar_Tspec_hdr;
  GenTspecParms     Guar_Tspec_parms;
  IntServParmHdr    Guar_Rspec_hdr;
  GuarRspec         Guar_Rspec;
} GuarFlowSpec;