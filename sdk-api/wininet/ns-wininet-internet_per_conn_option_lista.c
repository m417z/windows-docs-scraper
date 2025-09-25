typedef struct {
  DWORD                       dwSize;
  LPSTR                       pszConnection;
  DWORD                       dwOptionCount;
  DWORD                       dwOptionError;
  LPINTERNET_PER_CONN_OPTIONA pOptions;
} INTERNET_PER_CONN_OPTION_LISTA, *LPINTERNET_PER_CONN_OPTION_LISTA;