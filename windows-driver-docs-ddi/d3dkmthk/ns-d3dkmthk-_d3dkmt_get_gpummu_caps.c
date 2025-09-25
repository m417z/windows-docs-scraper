typedef struct _D3DKMT_GET_GPUMMU_CAPS {
  UINT                   PhysicalAdapterIndex;
  DXGK_ESCAPE_GPUMMUCAPS GpuMmuCaps;
} D3DKMT_GET_GPUMMU_CAPS;