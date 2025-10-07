typedef struct D3DINDEXBUFFER_DESC {
  D3DFORMAT       Format;
  D3DRESOURCETYPE Type;
  DWORD           Usage;
  D3DPOOL         Pool;
  UINT            Size;
} D3DINDEXBUFFER_DESC, *LPD3DINDEXBUFFER_DESC;