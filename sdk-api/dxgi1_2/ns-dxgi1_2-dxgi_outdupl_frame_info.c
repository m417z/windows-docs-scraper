typedef struct DXGI_OUTDUPL_FRAME_INFO {
  LARGE_INTEGER                 LastPresentTime;
  LARGE_INTEGER                 LastMouseUpdateTime;
  UINT                          AccumulatedFrames;
  BOOL                          RectsCoalesced;
  BOOL                          ProtectedContentMaskedOut;
  DXGI_OUTDUPL_POINTER_POSITION PointerPosition;
  UINT                          TotalMetadataBufferSize;
  UINT                          PointerShapeBufferSize;
} DXGI_OUTDUPL_FRAME_INFO;