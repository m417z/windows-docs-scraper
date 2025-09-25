typedef struct DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS {
  [in]     DXGI_DDI_HDEVICE                hDevice;
  [in/out] DXGI_GAMMA_CONTROL_CAPABILITIES *pGammaCapabilities;
} DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS;