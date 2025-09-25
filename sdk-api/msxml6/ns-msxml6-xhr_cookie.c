typedef struct tagXHR_COOKIE {
  WCHAR    *pwszUrl;
  WCHAR    *pwszName;
  WCHAR    *pwszValue;
  WCHAR    *pwszP3PPolicy;
  FILETIME ftExpires;
  DWORD    dwFlags;
} XHR_COOKIE;