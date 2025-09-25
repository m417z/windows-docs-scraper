typedef struct RILCALLHANDOVERSTATE {
  DWORD                cbSize;
  DWORD                dwParams;
  RILCALLHANDOVERPHASE dwPhase;
  RILCALLTYPE          dwOldType;
  RILCALLTYPE          dwNewType;
  DWORD                dw3gppCause;
} RILCALLHANDOVERSTATE, *LPRILCALLHANDOVERSTATE;