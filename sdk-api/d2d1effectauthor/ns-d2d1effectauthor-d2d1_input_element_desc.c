typedef struct D2D1_INPUT_ELEMENT_DESC {
  PCSTR       semanticName;
  UINT32      semanticIndex;
  DXGI_FORMAT format;
  UINT32      inputSlot;
  UINT32      alignedByteOffset;
} D2D1_INPUT_ELEMENT_DESC;