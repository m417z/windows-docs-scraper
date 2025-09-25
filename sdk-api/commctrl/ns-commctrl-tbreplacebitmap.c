typedef struct {
  HINSTANCE hInstOld;
  UINT_PTR  nIDOld;
  HINSTANCE hInstNew;
  UINT_PTR  nIDNew;
  int       nButtons;
} TBREPLACEBITMAP, *LPTBREPLACEBITMAP;