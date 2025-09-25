typedef struct _NOTIFYCANCEL {
  LPWSTR lpName;
  LPWSTR lpProvider;
  DWORD  dwFlags;
  BOOL   fForce;
} NOTIFYCANCEL, *LPNOTIFYCANCEL;