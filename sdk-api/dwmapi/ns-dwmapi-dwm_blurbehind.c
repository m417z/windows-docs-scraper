typedef struct _DWM_BLURBEHIND {
  DWORD dwFlags;
  BOOL  fEnable;
  HRGN  hRgnBlur;
  BOOL  fTransitionOnMaximized;
} DWM_BLURBEHIND, *PDWM_BLURBEHIND;