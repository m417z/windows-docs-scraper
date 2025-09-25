typedef struct _DXGKARGCB_MAPMDLTOIOMMU {
  [in]  PMDL   pMdl;
  [out] HANDLE hMemoryHandle;
} DXGKARGCB_MAPMDLTOIOMMU;