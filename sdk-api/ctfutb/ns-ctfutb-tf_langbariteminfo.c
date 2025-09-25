typedef struct TF_LANGBARITEMINFO {
  CLSID clsidService;
  GUID  guidItem;
  DWORD dwStyle;
  ULONG ulSort;
  WCHAR szDescription[32];
} TF_LANGBARITEMINFO;