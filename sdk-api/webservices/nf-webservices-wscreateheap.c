HRESULT WsCreateHeap(
  [in]           SIZE_T                 maxSize,
  [in]           SIZE_T                 trimSize,
  [in, optional] const WS_HEAP_PROPERTY *properties,
  [in]           ULONG                  propertyCount,
                 WS_HEAP                **heap,
  [in, optional] WS_ERROR               *error
);