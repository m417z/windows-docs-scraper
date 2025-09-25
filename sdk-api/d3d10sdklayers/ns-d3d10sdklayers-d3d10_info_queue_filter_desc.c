typedef struct D3D10_INFO_QUEUE_FILTER_DESC {
  UINT                   NumCategories;
  D3D10_MESSAGE_CATEGORY *pCategoryList;
  UINT                   NumSeverities;
  D3D10_MESSAGE_SEVERITY *pSeverityList;
  UINT                   NumIDs;
  D3D10_MESSAGE_ID       *pIDList;
} D3D10_INFO_QUEUE_FILTER_DESC;