typedef struct _DDICHECKOVERLAYSUPPORTINPUT {
  [in] UINT                    OverlayWidth;
  [in] UINT                    OverlayHeight;
       D3DDDIFORMAT            OverlayFormat;
  [in] UINT                    DisplayWidth;
  [in] UINT                    DisplayHeight;
  [in] UINT                    DisplayRefreshRate;
  [in] D3DDDIFORMAT            DisplayFormat;
  [in] D3DDDI_SCANLINEORDERING DisplayScanLineOrdering;
  [in] D3DDDI_ROTATION         DisplayRotation;
} DDICHECKOVERLAYSUPPORTINPUT;