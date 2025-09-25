typedef struct D3D11_INFO_QUEUE_FILTER_DESC {
  UINT                   NumCategories;
  D3D11_MESSAGE_CATEGORY *pCategoryList;
  UINT                   NumSeverities;
  D3D11_MESSAGE_SEVERITY *pSeverityList;
  UINT                   NumIDs;
  D3D11_MESSAGE_ID       *pIDList;
} D3D11_INFO_QUEUE_FILTER_DESC;