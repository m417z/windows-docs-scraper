typedef struct D2D1_CUSTOM_VERTEX_BUFFER_PROPERTIES {
  const BYTE                    *shaderBufferWithInputSignature;
  UINT32                        shaderBufferSize;
  const D2D1_INPUT_ELEMENT_DESC *inputElements;
  UINT32                        elementCount;
  UINT32                        stride;
} D2D1_CUSTOM_VERTEX_BUFFER_PROPERTIES;