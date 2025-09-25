typedef struct _SHQUERYRBINFO {
  DWORD     cbSize;
#if ...
  __int64   i64Size;
#if ...
  __int64   i64NumItems;
#else
  DWORDLONG i64Size;
#endif
#else
  DWORDLONG i64NumItems;
#endif
} SHQUERYRBINFO, *LPSHQUERYRBINFO;