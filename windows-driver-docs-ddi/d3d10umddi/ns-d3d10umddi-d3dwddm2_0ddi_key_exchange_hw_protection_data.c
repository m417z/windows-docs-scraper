typedef struct D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA {
  UINT                                                 HWProtectionFunctionID;
  D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA  *pInputData;
  D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA *pOutputData;
  HRESULT                                              Status;
} D3DWDDM2_0DDI_KEY_EXCHANGE_HW_PROTECTION_DATA;