WS_IS_DEFAULT_VALUE_CALLBACK WsIsDefaultValueCallback;

HRESULT WsIsDefaultValueCallback(
  [in]           const void *descriptionData,
                 const void *value,
                 const void *defaultValue,
  [in]           ULONG valueSize,
  [out]          BOOL *isDefault,
  [in, optional] WS_ERROR *error
)
{...}