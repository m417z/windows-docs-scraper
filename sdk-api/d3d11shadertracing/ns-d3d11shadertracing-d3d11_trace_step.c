typedef struct D3D11_TRACE_STEP {
  UINT                             ID;
  BOOL                             InstructionActive;
  UINT8                            NumRegistersWritten;
  UINT8                            NumRegistersRead;
  D3D11_TRACE_MISC_OPERATIONS_MASK MiscOperations;
  UINT                             OpcodeType;
  UINT64                           CurrentGlobalCycle;
} D3D11_TRACE_STEP;