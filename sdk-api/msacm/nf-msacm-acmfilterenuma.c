MMRESULT ACMAPI acmFilterEnumA(
  HACMDRIVER          had,
  LPACMFILTERDETAILSA pafd,
  ACMFILTERENUMCBA    fnCallback,
  DWORD_PTR           dwInstance,
  DWORD               fdwEnum
);