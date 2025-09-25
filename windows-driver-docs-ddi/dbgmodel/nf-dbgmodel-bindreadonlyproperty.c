Microsoft::WRL::ComPtr<IModelPropertyAccessor> BindReadOnlyProperty(
  T                                                                           *classObject,
  HRESULT(T::* )(PCWSTR key,IModelObject *contextObject,IModelObject **value) getMethod
);