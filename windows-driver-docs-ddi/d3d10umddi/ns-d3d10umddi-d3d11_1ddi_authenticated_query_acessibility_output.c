typedef struct D3D11_1DDI_AUTHENTICATED_QUERY_ACESSIBILITY_OUTPUT {
  D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT Output;
  D3D11_1DDI_BUS_TYPE                   BusType;
  BOOL                                  AccessibleInContiguousBlocks;
  BOOL                                  AccessibleInNonContiguousBlocks;
} D3D11_1DDI_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT;