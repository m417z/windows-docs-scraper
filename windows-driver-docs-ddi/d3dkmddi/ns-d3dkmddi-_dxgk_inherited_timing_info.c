typedef struct _DXGK_INHERITED_TIMING_INFO {
  union {
    D3DDDI_COLOR_SPACE_TYPE             OutputColorSpace;
    D3DDDI_OUTPUT_WIRE_COLOR_SPACE_TYPE OutputWireColorSpace;
  };
  D3DKMDT_WIRE_FORMAT_AND_PREFERENCE SelectedWireFormat;
  union {
    struct {
      DXGK_GLITCH_CAUSE    GlitchCause;
      DXGK_GLITCH_EFFECT   GlitchEffect;
      DXGK_GLITCH_DURATION GlitchDuration;
      UINT8                Reserved;
    };
    UINT DiagnosticInfo;
  };
} DXGK_INHERITED_TIMING_INFO, *PDXGK_INHERITED_TIMING_INFO;