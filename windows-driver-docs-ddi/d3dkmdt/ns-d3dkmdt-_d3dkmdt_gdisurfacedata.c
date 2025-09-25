typedef struct _D3DKMDT_GDISURFACEDATA {
  [in]  UINT                    Width;
  [in]  UINT                    Height;
  [in]  D3DDDIFORMAT            Format;
  [in]  D3DKMDT_GDISURFACETYPE  Type;
  [in]  D3DKMDT_GDISURFACEFLAGS Flags;
  [out] UINT                    Pitch;
} D3DKMDT_GDISURFACEDATA;