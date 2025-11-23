typedef struct D3D12DDI_GENERIC_PROGRAM_DESC_0108 {
  LPCWSTR                             ProgramName;
  UINT                                NumExports;
  LPCWSTR                             *pExports;
  UINT                                NumSubobjects;
  const D3D12DDI_STATE_SUBOBJECT_0054 const * * pSubobjects;
} D3D12DDI_GENERIC_PROGRAM_DESC_0108;