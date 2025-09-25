HRESULT WebSocketGetAction(
  [in]            WEB_SOCKET_HANDLE       hWebSocket,
  [in]            WEB_SOCKET_ACTION_QUEUE eActionQueue,
  [in, out]       WEB_SOCKET_BUFFER       *pDataBuffers,
  [in, out]       ULONG                   *pulDataBufferCount,
  [out]           WEB_SOCKET_ACTION       *pAction,
  [out]           WEB_SOCKET_BUFFER_TYPE  *pBufferType,
  [out, optional] PVOID                   *pvApplicationContext,
  [out]           PVOID                   *pvActionContext
);