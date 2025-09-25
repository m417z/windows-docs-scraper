typedef struct _D3DHAL_GLOBALDRIVERDATA {
  DWORD            dwSize;
  D3DDEVICEDESC_V1 hwCaps;
  DWORD            dwNumVertices;
  DWORD            dwNumClipVertices;
  DWORD            dwNumTextureFormats;
  LPDDSURFACEDESC  lpTextureFormats;
} D3DHAL_GLOBALDRIVERDATA;