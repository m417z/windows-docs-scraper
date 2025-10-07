typedef struct {
  DWORD          cbSize;
  DWORD          cRules;
  PST_ACCESSRULE *rgRules;
} PST_ACCESSRULESET, *PPST_ACCESSRULESET;