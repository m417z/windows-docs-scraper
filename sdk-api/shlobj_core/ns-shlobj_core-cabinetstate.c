typedef struct {
  WORD cLength;
  WORD nVersion;
  BOOL fFullPathTitle : 1;
  BOOL fSaveLocalView : 1;
  BOOL fNotShell : 1;
  BOOL fSimpleDefault : 1;
  BOOL fDontShowDescBar : 1;
  BOOL fNewWindowMode : 1;
  BOOL fShowCompColor : 1;
  BOOL fDontPrettyNames : 1;
  BOOL fAdminsCreateCommonGroups : 1;
  UINT fUnusedFlags : 7;
  UINT fMenuEnumFilter;
} CABINETSTATE, *LPCABINETSTATE;