typedef struct DXGI_DDI_BASE_ARGS {
  [in]     DXGI_DDI_BASE_CALLBACKS *pDXGIBaseCallbacks;
  union {
             DXGI1_6_1_DDI_BASE_FUNCTIONS *pDXGIDDIBaseFunctions6_1;
             DXGI1_5_DDI_BASE_FUNCTIONS   *pDXGIDDIBaseFunctions6;
             DXGI1_4_DDI_BASE_FUNCTIONS   *pDXGIDDIBaseFunctions5;
    [in/out] DXGI1_3_DDI_BASE_FUNCTIONS   *pDXGIDDIBaseFunctions4;
    [in/out] DXGI1_2_DDI_BASE_FUNCTIONS   *pDXGIDDIBaseFunctions3;
    [in/out] DXGI1_1_DDI_BASE_FUNCTIONS   *pDXGIDDIBaseFunctions2;
    [in/out] DXGI_DDI_BASE_FUNCTIONS      *pDXGIDDIBaseFunctions;
  };
} DXGI_DDI_BASE_ARGS;