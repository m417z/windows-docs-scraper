typedef struct tagSOUNDSENTRYA {
  UINT  cbSize;
  DWORD dwFlags;
  DWORD iFSTextEffect;
  DWORD iFSTextEffectMSec;
  DWORD iFSTextEffectColorBits;
  DWORD iFSGrafEffect;
  DWORD iFSGrafEffectMSec;
  DWORD iFSGrafEffectColor;
  DWORD iWindowsEffect;
  DWORD iWindowsEffectMSec;
  LPSTR lpszWindowsEffectDLL;
  DWORD iWindowsEffectOrdinal;
} SOUNDSENTRYA, *LPSOUNDSENTRYA;