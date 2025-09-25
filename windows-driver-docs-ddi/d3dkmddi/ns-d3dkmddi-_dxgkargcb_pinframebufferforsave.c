typedef struct _DXGKARGCB_PINFRAMEBUFFERFORSAVE {
  [in]  UINT   PhysicalAdapterIndex;
  [in]  SIZE_T CommitSize;
  [out] PMDL   pMdl;
} DXGKARGCB_PINFRAMEBUFFERFORSAVE;