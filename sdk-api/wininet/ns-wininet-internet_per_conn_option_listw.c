typedef struct {
  DWORD                       dwSize;
  LPWSTR                      pszConnection;
  DWORD                       dwOptionCount;
  DWORD                       dwOptionError;
  LPINTERNET_PER_CONN_OPTIONW pOptions;
} INTERNET_PER_CONN_OPTION_LISTW, *LPINTERNET_PER_CONN_OPTION_LISTW;