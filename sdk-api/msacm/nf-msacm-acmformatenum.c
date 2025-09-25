MMRESULT ACMAPI acmFormatEnum(
  HACMDRIVER         had,
  LPACMFORMATDETAILS pafd,
  ACMFORMATENUMCB    fnCallback,
  DWORD_PTR          dwInstance,
  DWORD              fdwEnum
);