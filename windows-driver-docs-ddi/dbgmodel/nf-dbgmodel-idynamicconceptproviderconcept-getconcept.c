HRESULT GetConcept(
  IModelObject *contextObject,
  REFIID       conceptId,
  IUnknown     **conceptInterface,
  IKeyStore    **conceptMetadata,
  bool         *hasConcept
);