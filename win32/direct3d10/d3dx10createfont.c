HRESULT D3DX10CreateFont(
  _In_  ID3D10Device *pDevice,
  _In_  INT          Height,
  _In_  UINT         Width,
  _In_  UINT         Weight,
  _In_  UINT         MipLevels,
  _In_  BOOL         Italic,
  _In_  UINT         CharSet,
  _In_  UINT         OutputPrecision,
  _In_  UINT         Quality,
  _In_  UINT         PitchAndFamily,
  _In_  LPCTSTR      pFaceName,
  _Out_ LPD3DX10FONT *ppFont
);