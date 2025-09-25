HRESULT WsGetHeapProperty(
  [in]           WS_HEAP             *heap,
  [in]           WS_HEAP_PROPERTY_ID id,
                 void                *value,
  [in]           ULONG               valueSize,
  [in, optional] WS_ERROR            *error
);