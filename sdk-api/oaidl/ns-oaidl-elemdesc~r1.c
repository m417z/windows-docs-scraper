typedef struct tagELEMDESC {
  TYPEDESC tdesc;
  union {
    IDLDESC   idldesc;
    PARAMDESC paramdesc;
  } DUMMYUNIONNAME;
} ELEMDESC, *LPELEMDESC;