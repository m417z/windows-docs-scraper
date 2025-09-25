typedef struct D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA {
  UINT   PrivateDataSize;
  UINT   MaxHWProtectionDataSize;
  UINT   HWProtectionDataSize;
  UINT64 TransportTime;
  UINT64 ExecutionTime;
  BYTE   pbOutput[4];
} D3D11_KEY_EXCHANGE_HW_PROTECTION_OUTPUT_DATA;