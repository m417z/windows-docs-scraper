typedef struct _D3DKMT_OUTPUTDUPL_FRAMEINFO {
  D3DKMT_ALIGN64 LARGE_INTEGER       LastPresentTime;
  D3DKMT_ALIGN64 LARGE_INTEGER       LastMouseUpdateTime;
  UINT                               AccumulatedFrames;
  BOOL                               RectsCoalesced;
  BOOL                               ProtectedContentMaskedOut;
  D3DKMT_OUTPUTDUPL_POINTER_POSITION PointerPosition;
  UINT                               TotalMetadataBufferSize;
  UINT                               PointerShapeBufferSize;
} D3DKMT_OUTPUTDUPL_FRAMEINFO;