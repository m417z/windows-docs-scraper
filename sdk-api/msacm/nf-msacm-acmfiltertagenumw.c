MMRESULT ACMAPI acmFilterTagEnumW(
  HACMDRIVER             had,
  LPACMFILTERTAGDETAILSW paftd,
  ACMFILTERTAGENUMCBW    fnCallback,
  DWORD_PTR              dwInstance,
  DWORD                  fdwEnum
);