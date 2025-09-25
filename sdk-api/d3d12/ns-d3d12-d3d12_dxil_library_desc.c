typedef struct D3D12_DXIL_LIBRARY_DESC {
  D3D12_SHADER_BYTECODE   DXILLibrary;
  UINT                    NumExports;
  const D3D12_EXPORT_DESC *pExports;
} D3D12_DXIL_LIBRARY_DESC;