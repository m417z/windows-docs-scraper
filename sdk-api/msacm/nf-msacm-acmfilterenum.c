MMRESULT ACMAPI acmFilterEnum(
  HACMDRIVER         had,
  LPACMFILTERDETAILS pafd,
  ACMFILTERENUMCB    fnCallback,
  DWORD_PTR          dwInstance,
  DWORD              fdwEnum
);