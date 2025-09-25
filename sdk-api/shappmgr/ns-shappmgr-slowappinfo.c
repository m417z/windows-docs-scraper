typedef struct _tagSlowAppInfo {
  ULONGLONG ullSize;
  FILETIME  ftLastUsed;
  int       iTimesUsed;
  LPWSTR    pszImage;
} SLOWAPPINFO, *PSLOWAPPINFO;