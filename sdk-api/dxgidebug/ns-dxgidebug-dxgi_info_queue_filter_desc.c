typedef struct DXGI_INFO_QUEUE_FILTER_DESC {
  UINT                             NumCategories;
  DXGI_INFO_QUEUE_MESSAGE_CATEGORY *pCategoryList;
  UINT                             NumSeverities;
  DXGI_INFO_QUEUE_MESSAGE_SEVERITY *pSeverityList;
  UINT                             NumIDs;
  DXGI_INFO_QUEUE_MESSAGE_ID       *pIDList;
} DXGI_INFO_QUEUE_FILTER_DESC;