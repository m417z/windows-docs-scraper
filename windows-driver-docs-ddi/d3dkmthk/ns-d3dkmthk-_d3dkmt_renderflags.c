typedef struct _D3DKMT_RENDERFLAGS {
  UINT ResizeCommandBuffer : 1;
  UINT ResizeAllocationList : 1;
  UINT ResizePatchLocationList : 1;
  UINT NullRendering : 1;
  UINT PresentRedirected : 1;
  UINT RenderKm : 1;
  UINT RenderKmReadback : 1;
  UINT Reserved : 25;
} D3DKMT_RENDERFLAGS;