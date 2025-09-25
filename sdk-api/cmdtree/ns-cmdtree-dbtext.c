typedef struct tagDBTEXT {
  LPOLESTR pwszText;
  ULONG    ulErrorLocator;
  ULONG    ulTokenLength;
  GUID     guidDialect;
} DBTEXT;