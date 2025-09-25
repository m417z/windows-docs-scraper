typedef struct D3D10DDIARG_INPUT_ELEMENT_DESC {
  [in] UINT                           InputSlot;
  [in] UINT                           AlignedByteOffset;
  [in] DXGI_FORMAT                    Format;
  [in] D3D10_DDI_INPUT_CLASSIFICATION InputSlotClass;
  [in] UINT                           InstanceDataStepRate;
  [in] UINT                           InputRegister;
} D3D10DDIARG_INPUT_ELEMENT_DESC;