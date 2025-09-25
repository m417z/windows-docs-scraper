typedef struct _tagRasNapState {
  DWORD          dwSize;
  DWORD          dwFlags;
  IsolationState isolationState;
  ProbationTime  probationTime;
} RASNAPSTATE, *LPRASNAPSTATE;