typedef struct {
  DWORD           cbStruct;
  DWORD           dwOptions;
  PFN_AUTH_NOTIFY pfnNotify;
  DWORD_PTR       dwContext;
} INTERNET_AUTH_NOTIFY_DATA;