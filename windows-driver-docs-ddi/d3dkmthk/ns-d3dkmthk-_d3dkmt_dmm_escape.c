typedef struct _D3DKMT_DMM_ESCAPE {
  D3DKMT_DMMESCAPETYPE         Type;
  D3DKMT_ALIGN64 D3DKMT_SIZE_T ProvidedBufferSize;
  D3DKMT_ALIGN64 D3DKMT_SIZE_T MinRequiredBufferSize;
  UCHAR                        Data[1];
} D3DKMT_DMM_ESCAPE;