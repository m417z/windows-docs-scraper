HRESULT AcquireFilteredSubNamespace(
  PCWSTR                          modelName,
  PCWSTR                          subNamespaceModelName,
  PCWSTR                          accessName,
  IKeyStore                       *metadata,
  IModelMethod                    *filter,
  IModelObject                    **namespaceModelObject,
  IFilteredNamespacePropertyToken **token
);