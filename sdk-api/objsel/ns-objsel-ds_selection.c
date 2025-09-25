typedef struct _DS_SELECTION {
  PWSTR   pwzName;
  PWSTR   pwzADsPath;
  PWSTR   pwzClass;
  PWSTR   pwzUPN;
  VARIANT *pvarFetchedAttributes;
  ULONG   flScopeType;
} DS_SELECTION, *PDS_SELECTION;