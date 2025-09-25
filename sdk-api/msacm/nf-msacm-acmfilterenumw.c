MMRESULT ACMAPI acmFilterEnumW(
  HACMDRIVER          had,
  LPACMFILTERDETAILSW pafd,
  ACMFILTERENUMCBW    fnCallback,
  DWORD_PTR           dwInstance,
  DWORD               fdwEnum
);