typedef struct _D3DDDIARG_DRAWINDEXEDPRIMITIVE2 {
  [in] D3DPRIMITIVETYPE PrimitiveType;
  [in] INT              BaseVertexOffset;
  [in] UINT             MinIndex;
  [in] UINT             NumVertices;
  [in] UINT             StartIndexOffset;
  [in] UINT             PrimitiveCount;
} D3DDDIARG_DRAWINDEXEDPRIMITIVE2;