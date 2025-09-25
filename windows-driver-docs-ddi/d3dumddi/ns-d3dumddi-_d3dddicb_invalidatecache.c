typedef struct _D3DDDICB_INVALIDATECACHE {
  D3DKMT_HANDLE hAllocation;
  SIZE_T        Offset;
  SIZE_T        Length;
} D3DDDICB_INVALIDATECACHE;