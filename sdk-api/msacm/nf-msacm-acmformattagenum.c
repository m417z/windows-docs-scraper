MMRESULT ACMAPI acmFormatTagEnum(
  HACMDRIVER            had,
  LPACMFORMATTAGDETAILS paftd,
  ACMFORMATTAGENUMCB    fnCallback,
  DWORD_PTR             dwInstance,
  DWORD                 fdwEnum
);