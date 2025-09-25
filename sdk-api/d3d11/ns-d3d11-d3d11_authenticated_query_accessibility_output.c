typedef struct D3D11_AUTHENTICATED_QUERY_ACESSIBILITY_OUTPUT {
  D3D11_AUTHENTICATED_QUERY_OUTPUT Output;
  D3D11_BUS_TYPE                   BusType;
  BOOL                             AccessibleInContiguousBlocks;
  BOOL                             AccessibleInNonContiguousBlocks;
} D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT;