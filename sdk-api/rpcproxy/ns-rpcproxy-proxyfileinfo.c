typedef struct tagProxyFileInfo {
  const PCInterfaceProxyVtblList *pProxyVtblList;
  const PCInterfaceStubVtblList  *pStubVtblList;
  const PCInterfaceName          *pNamesArray;
  const IID                      **pDelegatedIIDs;
  PIIDLookup                     pIIDLookupRtn;
  unsigned short                 TableSize;
  unsigned short                 TableVersion;
  const IID                      **pAsyncIIDLookup;
  LONG_PTR                       Filler2;
  LONG_PTR                       Filler3;
  LONG_PTR                       Filler4;
} ProxyFileInfo;