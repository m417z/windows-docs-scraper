typedef struct tagDBID {
  union {
    GUID guid;
    GUID *pguid;
  } uGuid;
  DBKIND eKind;
  union {
    wchar_t       *pwszName;
    unsigned long ulPropid;
  } uName;
} DBID;