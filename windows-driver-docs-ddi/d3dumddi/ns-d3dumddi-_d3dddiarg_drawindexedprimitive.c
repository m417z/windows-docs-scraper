typedef struct _D3DDDIARG_DRAWINDEXEDPRIMITIVE {
  [in] D3DPRIMITIVETYPE PrimitiveType;
  [in] INT              BaseVertexIndex;
  [in] UINT             MinIndex;
  [in] UINT             NumVertices;
  [in] UINT             StartIndex;
  [in] UINT             PrimitiveCount;
} D3DDDIARG_DRAWINDEXEDPRIMITIVE;