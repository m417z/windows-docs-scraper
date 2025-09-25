HRESULT GetNext(
  BSTR         *keyName,
  BSTR         *actionName,
  BSTR         *actionDescription,
  bool         *actionIsDefault,
  IModelObject **actionMethod,
  IKeyStore    **metadta
);