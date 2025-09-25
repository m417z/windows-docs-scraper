typedef struct DXGI_GAMMA_CONTROL_CAPABILITIES {
  [out] BOOL  ScaleAndOffsetSupported;
  [out] float MaxConvertedValue;
  [out] float MinConvertedValue;
  [out] UINT  NumGammaControlPoints;
        float ControlPointPositions[1025];
} DXGI_GAMMA_CONTROL_CAPABILITIES;