typedef struct tagTYPEDESC {
  union {
    struct tagTYPEDESC  *lptdesc;
    struct tagARRAYDESC *lpadesc;
    HREFTYPE            hreftype;
  } DUMMYUNIONNAME;
  VARTYPE vt;
} TYPEDESC;