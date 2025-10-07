typedef struct {
  DWORD     helpID;
  DWORD     exStyle;
  DWORD     style;
  short     x;
  short     y;
  short     cx;
  short     cy;
  DWORD     id;
  sz_Or_Ord windowClass;
  sz_Or_Ord title;
  WORD      extraCount;
} DLGITEMTEMPLATEEX;