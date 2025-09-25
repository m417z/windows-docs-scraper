typedef struct _D3DDeviceDesc_V1 {
  DWORD            dwSize;
  DWORD            dwFlags;
  D3DCOLORMODEL    dcmColorModel;
  DWORD            dwDevCaps;
  D3DTRANSFORMCAPS dtcTransformCaps;
  BOOL             bClipping;
  D3DLIGHTINGCAPS  dlcLightingCaps;
  D3DPRIMCAPS      dpcLineCaps;
  D3DPRIMCAPS      dpcTriCaps;
  DWORD            dwDeviceRenderBitDepth;
  DWORD            dwDeviceZBufferBitDepth;
  DWORD            dwMaxBufferSize;
  DWORD            dwMaxVertexCount;
} D3DDEVICEDESC_V1, *LPD3DDEVICEDESC_V1;