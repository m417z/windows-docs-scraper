typedef struct _KBUGCHECK_ADD_PAGES {
  PVOID     Context;
  ULONG     Flags;
  ULONG     BugCheckCode;
  ULONG_PTR Address;
  ULONG_PTR Count;
} KBUGCHECK_ADD_PAGES, *PKBUGCHECK_ADD_PAGES;