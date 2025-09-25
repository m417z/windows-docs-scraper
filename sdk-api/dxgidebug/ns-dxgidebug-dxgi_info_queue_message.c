typedef struct DXGI_INFO_QUEUE_MESSAGE {
  DXGI_DEBUG_ID                    Producer;
  DXGI_INFO_QUEUE_MESSAGE_CATEGORY Category;
  DXGI_INFO_QUEUE_MESSAGE_SEVERITY Severity;
  DXGI_INFO_QUEUE_MESSAGE_ID       ID;
  const char                       *pDescription;
  SIZE_T                           DescriptionByteLength;
} DXGI_INFO_QUEUE_MESSAGE;