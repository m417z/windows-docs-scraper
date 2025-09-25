typedef struct _SCOPEDATAITEM {
  DWORD      mask;
  LPOLESTR   displayname;
  int        nImage;
  int        nOpenImage;
  UINT       nState;
  int        cChildren;
  LPARAM     lParam;
  HSCOPEITEM relativeID;
  HSCOPEITEM ID;
} SCOPEDATAITEM;