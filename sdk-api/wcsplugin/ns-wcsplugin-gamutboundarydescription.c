typedef struct _GamutBoundaryDescription {
  PrimaryJabColors *pPrimaries;
  UINT             cNeutralSamples;
  JabColorF        *pNeutralSamples;
  GamutShell       *pReferenceShell;
  GamutShell       *pPlausibleShell;
  GamutShell       *pPossibleShell;
} GamutBoundaryDescription;