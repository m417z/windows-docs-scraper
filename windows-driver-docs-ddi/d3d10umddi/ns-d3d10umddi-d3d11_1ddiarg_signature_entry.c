typedef struct D3D11_1DDIARG_SIGNATURE_ENTRY {
  [in] D3D10_SB_NAME                    SystemValue;
  [in] UINT                             Register;
  [in] BYTE                             Mask;
       D3D10_SB_REGISTER_COMPONENT_TYPE RegisterComponentType;
       D3D11_SB_OPERAND_MIN_PRECISION   MinPrecision;
} D3D11_1DDIARG_SIGNATURE_ENTRY;