typedef struct tagMENUINFO {
  DWORD     cbSize;
  DWORD     fMask;
  DWORD     dwStyle;
  UINT      cyMax;
  HBRUSH    hbrBack;
  DWORD     dwContextHelpID;
  ULONG_PTR dwMenuData;
} MENUINFO, *LPMENUINFO;