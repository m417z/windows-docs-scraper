typedef struct tACMFORMATCHOOSE {
  DWORD                   cbStruct;
  DWORD                   fdwStyle;
  HWND                    hwndOwner;
  LPWAVEFORMATEX          pwfx;
  DWORD                   cbwfx;
  LPCSTR                  pszTitle;
  char                    szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
  char                    szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
  LPSTR                   pszName;
  DWORD                   cchName;
  DWORD                   fdwEnum;
  LPWAVEFORMATEX          pwfxEnum;
  HINSTANCE               hInstance;
  LPCSTR                  pszTemplateName;
  LPARAM                  lCustData;
  ACMFORMATCHOOSEHOOKPROC pfnHook;
} ACMFORMATCHOOSE, *PACMFORMATCHOOSE, *LPACMFORMATCHOOSE;