Microsoft::WRL::ComPtr<IModelPropertyAccessor> BindProperty(
  T                                                                           *classObject,
  HRESULT(T::* )(PCWSTR key,IModelObject *contextObject,IModelObject **value) getMethod,
  HRESULT(T::* )(PCWSTR key,IModelObject *contextObject,IModelObject **value) setMethod
);