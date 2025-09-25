typedef struct _D3DDDICB_RENDERFLAGS {
  union {
    struct {
      UINT ResizeCommandBuffer : 1;
      UINT ResizeAllocationList : 1;
      UINT ResizePatchLocationList : 1;
      UINT NullRendering : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} D3DDDICB_RENDERFLAGS;