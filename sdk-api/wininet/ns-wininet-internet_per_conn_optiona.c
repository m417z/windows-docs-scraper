typedef struct {
  DWORD dwOption;
  union {
    DWORD    dwValue;
    LPSTR    pszValue;
    FILETIME ftValue;
  } Value;
} INTERNET_PER_CONN_OPTIONA, *LPINTERNET_PER_CONN_OPTIONA;