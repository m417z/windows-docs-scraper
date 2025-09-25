typedef struct D3D11_SO_DECLARATION_ENTRY {
  UINT   Stream;
  LPCSTR SemanticName;
  UINT   SemanticIndex;
  BYTE   StartComponent;
  BYTE   ComponentCount;
  BYTE   OutputSlot;
} D3D11_SO_DECLARATION_ENTRY;