typedef struct _reobject {
  DWORD           cbStruct;
  LONG            cp;
  CLSID           clsid;
  LPOLEOBJECT     poleobj;
  LPSTORAGE       pstg;
  LPOLECLIENTSITE polesite;
  SIZEL           sizel;
  DWORD           dvaspect;
  DWORD           dwFlags;
  DWORD           dwUser;
} REOBJECT;