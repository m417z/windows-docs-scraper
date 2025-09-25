HRESULT GetMostDerivedObject(
  IDebugHostContext *pContext,
  Location          location,
  IDebugHostType    *objectType,
  Location          *derivedLocation,
  IDebugHostType    **derivedType
);