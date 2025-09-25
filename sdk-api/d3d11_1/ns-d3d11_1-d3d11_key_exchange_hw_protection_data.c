typedef struct D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA {
  UINT                                         HWProtectionFunctionID;
  D3D11_KEY_EXCHANGE_HW_PROTECTION_INPUT_DATA  *pInputData;
  D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA *pOutputData;
  HRESULT                                      Status;
} D3D11_KEY_EXCHANGE_HW_PROTECTION_DATA;