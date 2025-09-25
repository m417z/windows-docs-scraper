typedef struct D3D12_INFO_QUEUE_FILTER_DESC {
  UINT                   NumCategories;
  D3D12_MESSAGE_CATEGORY *pCategoryList;
  UINT                   NumSeverities;
  D3D12_MESSAGE_SEVERITY *pSeverityList;
  UINT                   NumIDs;
  D3D12_MESSAGE_ID       *pIDList;
} D3D12_INFO_QUEUE_FILTER_DESC;