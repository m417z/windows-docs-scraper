typedef struct RILPERSODEACTIVATIONSTATE {
  DWORD                                 cbSize;
  DWORD                                 dwParams;
  RILPERSODEACTIVATIONSTATEDEPERSOSTATE dwDePersoState;
  DWORD                                 dwNumCKAttemptsLeft;
  DWORD                                 dwNumPUKAttemptsLeft;
} RILPERSODEACTIVATIONSTATE, *LPRILPERSODEACTIVATIONSTATE;