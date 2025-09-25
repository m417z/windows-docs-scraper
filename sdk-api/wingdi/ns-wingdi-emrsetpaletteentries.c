typedef struct tagEMRSETPALETTEENTRIES {
  EMR          emr;
  DWORD        ihPal;
  DWORD        iStart;
  DWORD        cEntries;
  PALETTEENTRY aPalEntries[1];
} EMRSETPALETTEENTRIES, *PEMRSETPALETTEENTRIES;