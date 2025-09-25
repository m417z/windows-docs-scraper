typedef struct D3D12_SO_DECLARATION_ENTRY {
  UINT   Stream;
  LPCSTR SemanticName;
  UINT   SemanticIndex;
  BYTE   StartComponent;
  BYTE   ComponentCount;
  BYTE   OutputSlot;
} D3D12_SO_DECLARATION_ENTRY;