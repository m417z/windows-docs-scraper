typedef struct _SendTargets_IN {
  ULONGLONG UniqueSessionId;
  WCHAR     SendTargetsText[223 + 1];
} SendTargets_IN, *PSendTargets_IN;