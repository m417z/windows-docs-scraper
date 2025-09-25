MMRESULT ACMAPI acmFilterTagEnum(
  HACMDRIVER            had,
  LPACMFILTERTAGDETAILS paftd,
  ACMFILTERTAGENUMCB    fnCallback,
  DWORD_PTR             dwInstance,
  DWORD                 fdwEnum
);