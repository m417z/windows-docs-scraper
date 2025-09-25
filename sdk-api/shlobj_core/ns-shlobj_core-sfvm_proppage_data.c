typedef struct _SFVM_PROPPAGE_DATA {
  DWORD                dwReserved;
  LPFNADDPROPSHEETPAGE pfn;
  LPARAM               lParam;
} SFVM_PROPPAGE_DATA;