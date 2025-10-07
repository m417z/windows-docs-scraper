typedef struct _ANDEXP {
  DWORD        nPatternMatches;
  PATTERNMATCH PatternMatch[MAX_PATTERNS];
} ANDEXP, *LPANDEXP;