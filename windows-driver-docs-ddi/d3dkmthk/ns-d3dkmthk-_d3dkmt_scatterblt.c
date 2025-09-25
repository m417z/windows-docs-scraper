typedef struct _D3DKMT_SCATTERBLT {
  D3DKMT_ALIGN64 ULONG64 hLogicalSurfaceDestination;
  D3DKMT_ALIGN64 LONG64  hDestinationCompSurfDWM;
  D3DKMT_ALIGN64 UINT64  DestinationCompositionBindingId;
  RECT                   SourceRect;
  POINT                  DestinationOffset;
} D3DKMT_SCATTERBLT;