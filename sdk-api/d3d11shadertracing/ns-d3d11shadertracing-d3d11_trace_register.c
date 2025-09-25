typedef struct D3D11_TRACE_REGISTER {
  D3D11_TRACE_REGISTER_TYPE RegType;
  union {
    UINT16 Index1D;
    UINT16 Index2D[2];
  };
  UINT8                     OperandIndex;
  UINT8                     Flags;
} D3D11_TRACE_REGISTER;