typedef struct tagSOUNDSENTRYW {
  UINT   cbSize;
  DWORD  dwFlags;
  DWORD  iFSTextEffect;
  DWORD  iFSTextEffectMSec;
  DWORD  iFSTextEffectColorBits;
  DWORD  iFSGrafEffect;
  DWORD  iFSGrafEffectMSec;
  DWORD  iFSGrafEffectColor;
  DWORD  iWindowsEffect;
  DWORD  iWindowsEffectMSec;
  LPWSTR lpszWindowsEffectDLL;
  DWORD  iWindowsEffectOrdinal;
} SOUNDSENTRYW, *LPSOUNDSENTRYW;