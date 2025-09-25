HRESULT WsCall(
  [in]           WS_SERVICE_PROXY               *serviceProxy,
  [in]           const WS_OPERATION_DESCRIPTION *operation,
  [in, optional] const void                     **arguments,
  [in]           WS_HEAP                        *heap,
                 const WS_CALL_PROPERTY         *callProperties,
  [in]           const ULONG                    callPropertyCount,
  [in, optional] const WS_ASYNC_CONTEXT         *asyncContext,
  [in, optional] WS_ERROR                       *error
);