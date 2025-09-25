HRESULT GetMessage(
  [in]            DXGI_DEBUG_ID           Producer,
  [in]            UINT64                  MessageIndex,
  [out, optional] DXGI_INFO_QUEUE_MESSAGE *pMessage,
  [in, out]       SIZE_T                  *pMessageByteLength
);