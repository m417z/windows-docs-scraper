typedef struct D3D10_SO_DECLARATION_ENTRY {
  LPCSTR SemanticName;
  UINT   SemanticIndex;
  BYTE   StartComponent;
  BYTE   ComponentCount;
  BYTE   OutputSlot;
} D3D10_SO_DECLARATION_ENTRY;