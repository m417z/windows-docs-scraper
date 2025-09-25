typedef struct _D3DDDIARG_FLIPOVERLAY {
  [in] HANDLE                  hOverlay;
  [in] HANDLE                  hSource;
  [in] UINT                    SourceIndex;
  [in] D3DDDI_FLIPOVERLAYFLAGS Flags;
} D3DDDIARG_FLIPOVERLAY;