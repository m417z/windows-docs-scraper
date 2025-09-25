typedef struct tagHELPWININFOW {
  int   wStructSize;
  int   x;
  int   y;
  int   dx;
  int   dy;
  int   wMax;
  WCHAR rgchMember[2];
} HELPWININFOW, *PHELPWININFOW, *LPHELPWININFOW;