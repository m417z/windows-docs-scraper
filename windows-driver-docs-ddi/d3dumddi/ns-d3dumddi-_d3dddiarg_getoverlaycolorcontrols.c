typedef struct _D3DDDIARG_GETOVERLAYCOLORCONTROLS {
  [in]  HANDLE                      hOverlay;
  [in]  HANDLE                      hResource;
  [out] D3DDDI_OVERLAYCOLORCONTROLS ColorControls;
} D3DDDIARG_GETOVERLAYCOLORCONTROLS;