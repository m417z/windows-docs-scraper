typedef struct _D3DKMT_GET_POST_COMPOSITION_CAPS {
        D3DKMT_HANDLE                  hAdapter;
        D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [out] float                          MaxStretchFactor;
  [out] float                          MaxShrinkFactor;
} D3DKMT_GET_POST_COMPOSITION_CAPS;