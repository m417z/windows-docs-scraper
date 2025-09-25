MMRESULT ACMAPI acmStreamOpen(
  LPHACMSTREAM   phas,
  HACMDRIVER     had,
  LPWAVEFORMATEX pwfxSrc,
  LPWAVEFORMATEX pwfxDst,
  LPWAVEFILTER   pwfltr,
  DWORD_PTR      dwCallback,
  DWORD_PTR      dwInstance,
  DWORD          fdwOpen
);