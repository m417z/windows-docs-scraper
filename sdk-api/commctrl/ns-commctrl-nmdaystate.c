typedef struct tagNMDAYSTATE {
  NMHDR           nmhdr;
  SYSTEMTIME      stStart;
  int             cDayState;
  LPMONTHDAYSTATE prgDayState;
} NMDAYSTATE, *LPNMDAYSTATE;