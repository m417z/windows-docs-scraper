typedef struct {
  PWSTR    pwszName;
  PWSTR    pwszValue;
  PWSTR    pwszDomain;
  PWSTR    pwszPath;
  DWORD    dwFlags;
  FILETIME ftExpires;
  BOOL     fExpiresSet;
} INTERNET_COOKIE2;