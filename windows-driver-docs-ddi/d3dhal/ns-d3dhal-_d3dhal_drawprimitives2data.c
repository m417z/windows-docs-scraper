typedef struct _D3DHAL_DRAWPRIMITIVES2DATA {
  ULONG_PTR                 dwhContext;
  DWORD                     dwFlags;
  DWORD                     dwVertexType;
  LPDDRAWI_DDRAWSURFACE_LCL lpDDCommands;
  DWORD                     dwCommandOffset;
  DWORD                     dwCommandLength;
  union {
    LPDDRAWI_DDRAWSURFACE_LCL lpDDVertex;
    LPVOID                    lpVertices;
  };
  DWORD                     dwVertexOffset;
  DWORD                     dwVertexLength;
  DWORD                     dwReqVertexBufSize;
  DWORD                     dwReqCommandBufSize;
  LPDWORD                   lpdwRStates;
  union {
    DWORD   dwVertexSize;
    HRESULT ddrval;
  };
  DWORD                     dwErrorOffset;
} D3DHAL_DRAWPRIMITIVES2DATA;