typedef struct RILPSMEDIACONFIGURATIONSET {
  DWORD                   cbSize;
  DWORD                   dwExecutor;
  DWORD                   dwNumMediaConfiguration;
  RILPSMEDIACONFIGURATION stMediaConfiguration[1];
} RILPSMEDIACONFIGURATIONSET, *LPRILPSMEDIACONFIGURATIONSET;