typedef struct {
  DWORD langid : 16;
  DWORD fNumeric : 1;
  DWORD fComplex : 1;
  DWORD fNeedsWordBreaking : 1;
  DWORD fNeedsCaretInfo : 1;
  DWORD bCharSet : 8;
  DWORD fControl : 1;
  DWORD fPrivateUseArea : 1;
  DWORD fNeedsCharacterJustify : 1;
  DWORD fInvalidGlyph : 1;
  DWORD fInvalidLogAttr : 1;
  DWORD fCDM : 1;
  DWORD fAmbiguousCharSet : 1;
  DWORD fClusterSizeVaries : 1;
  DWORD fRejectInvalid : 1;
} SCRIPT_PROPERTIES;