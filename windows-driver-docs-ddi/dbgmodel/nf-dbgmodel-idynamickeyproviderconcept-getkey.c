HRESULT GetKey(
  IModelObject *contextObject,
  PCWSTR       key,
  IModelObject **keyValue,
  IKeyStore    **metadata,
  bool         *hasKey
);