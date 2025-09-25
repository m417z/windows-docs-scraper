HRESULT Execute(
  [in]           UINT32               commandId,
  [in]           UI_EXECUTIONVERB     verb,
  [in, optional] const PROPERTYKEY    *key,
  [in, optional] const PROPVARIANT    *currentValue,
  [in, optional] IUISimplePropertySet *commandExecutionProperties
);