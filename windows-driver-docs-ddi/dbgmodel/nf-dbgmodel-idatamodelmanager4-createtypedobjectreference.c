HRESULT CreateTypedObjectReference(
  IDebugHostContext           *context,
  Location                    objectLocation,
  IDebugHostType              *objectType,
  _COM_Errorptr_ IModelObject **object
);