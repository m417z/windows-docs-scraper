typedef struct _D3DKMT_SETGAMMARAMP {
  [in] D3DKMT_HANDLE                  hDevice;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] D3DDDI_GAMMARAMP_TYPE          Type;
  union {
    [in] D3DDDI_GAMMA_RAMP_RGB256x3x16 *pGammaRampRgb256x3x16;
    [in] D3DDDI_GAMMA_RAMP_DXGI_1      *pGammaRampDXGI1;
  };
  [in] UINT                           Size;
} D3DKMT_SETGAMMARAMP;