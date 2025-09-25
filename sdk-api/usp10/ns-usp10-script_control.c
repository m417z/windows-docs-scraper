typedef struct tag_SCRIPT_CONTROL {
  DWORD uDefaultLanguage : 16;
  DWORD fContextDigits : 1;
  DWORD fInvertPreBoundDir : 1;
  DWORD fInvertPostBoundDir : 1;
  DWORD fLinkStringBefore : 1;
  DWORD fLinkStringAfter : 1;
  DWORD fNeutralOverride : 1;
  DWORD fNumericOverride : 1;
  DWORD fLegacyBidiClass : 1;
  DWORD fMergeNeutralItems : 1;
  DWORD fUseStandardBidi : 1;
  DWORD fReserved : 6;
} SCRIPT_CONTROL;