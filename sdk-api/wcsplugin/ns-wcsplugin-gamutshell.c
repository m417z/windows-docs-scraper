typedef struct _GamutShell {
  FLOAT              JMin;
  FLOAT              JMax;
  UINT               cVertices;
  UINT               cTriangles;
  JabColorF          *pVertices;
  GamutShellTriangle *pTriangles;
} GamutShell;