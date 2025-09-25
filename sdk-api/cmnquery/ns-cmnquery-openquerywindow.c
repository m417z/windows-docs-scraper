typedef struct {
  DWORD         cbStruct;
  DWORD         dwFlags;
  CLSID         clsidHandler;
  LPVOID        pHandlerParameters;
  CLSID         clsidDefaultForm;
  IPersistQuery *pPersistQuery;
  union {
    void         *pFormParameters;
    IPropertyBag *ppbFormParameters;
  };
} OPENQUERYWINDOW, *LPOPENQUERYWINDOW;