WS_DYNAMIC_STRING_CALLBACK WsDynamicStringCallback;

HRESULT WsDynamicStringCallback(
  [in]           void *callbackState,
  [in]           const WS_XML_STRING *string,
  [out]          BOOL *found,
  [out]          ULONG *id,
  [in, optional] WS_ERROR *error
)
{...}