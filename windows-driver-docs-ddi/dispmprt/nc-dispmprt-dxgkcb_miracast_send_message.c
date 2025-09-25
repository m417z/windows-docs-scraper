DXGKCB_MIRACAST_SEND_MESSAGE DxgkcbMiracastSendMessage;

NTSTATUS DxgkcbMiracastSendMessage(
  [in]           HANDLE MiracastHandle,
  [in]           ULONG InputBufferSize,
  [in]           VOID *pInputBuffer,
  [in]           ULONG OutputBufferSize,
  [out]          VOID *pOutputBuffer,
  [in, optional] DXGKCB_MIRACAST_SEND_MESSAGE_CALLBACK pCallback,
  [in, optional] PVOID pCallbackContext
)
{...}