MMRESULT ACMAPI acmFormatEnumW(
  HACMDRIVER          had,
  LPACMFORMATDETAILSW pafd,
  ACMFORMATENUMCBW    fnCallback,
  DWORD_PTR           dwInstance,
  DWORD               fdwEnum
);