typedef struct _getcontextmenuex {
  CHARRANGE chrg;
  DWORD     dwFlags;
  POINT     pt;
  void      *pvReserved;
} GETCONTEXTMENUEX;