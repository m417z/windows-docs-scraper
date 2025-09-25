HRESULT AddMessage(
  [in] DXGI_DEBUG_ID                    Producer,
  [in] DXGI_INFO_QUEUE_MESSAGE_CATEGORY Category,
  [in] DXGI_INFO_QUEUE_MESSAGE_SEVERITY Severity,
  [in] DXGI_INFO_QUEUE_MESSAGE_ID       ID,
  [in] LPCSTR                           pDescription
);