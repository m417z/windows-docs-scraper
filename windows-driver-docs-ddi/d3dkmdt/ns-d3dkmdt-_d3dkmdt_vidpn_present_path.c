typedef struct _D3DKMDT_VIDPN_PRESENT_PATH {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID            VidPnSourceId;
  D3DDDI_VIDEO_PRESENT_TARGET_ID            VidPnTargetId;
  D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE     ImportanceOrdinal;
  D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION ContentTransformation;
  D3DKMDT_2DOFFSET                          VisibleFromActiveTLOffset;
  D3DKMDT_2DOFFSET                          VisibleFromActiveBROffset;
  D3DKMDT_COLOR_BASIS                       VidPnTargetColorBasis;
  D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES        VidPnTargetColorCoeffDynamicRanges;
  D3DKMDT_VIDPN_PRESENT_PATH_CONTENT        Content;
  D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION CopyProtection;
  D3DKMDT_GAMMA_RAMP                        GammaRamp;
} D3DKMDT_VIDPN_PRESENT_PATH;