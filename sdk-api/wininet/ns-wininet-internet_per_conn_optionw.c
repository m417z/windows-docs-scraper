typedef struct {
  DWORD dwOption;
  union {
    DWORD    dwValue;
    LPWSTR   pszValue;
    FILETIME ftValue;
  } Value;
} INTERNET_PER_CONN_OPTIONW, *LPINTERNET_PER_CONN_OPTIONW;