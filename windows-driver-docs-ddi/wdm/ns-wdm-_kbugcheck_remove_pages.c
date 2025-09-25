typedef struct _KBUGCHECK_REMOVE_PAGES {
  PVOID     Context;
  ULONG     Flags;
  ULONG     BugCheckCode;
  ULONG_PTR Address;
  ULONG_PTR Count;
} KBUGCHECK_REMOVE_PAGES, *PKBUGCHECK_REMOVE_PAGES;