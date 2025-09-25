typedef struct D3D12DDIARG_CREATE_SHADER_0026 {
  D3D12DDI_HROOTSIGNATURE         hRootSignature;
  const UINT                      *pShaderCode;
  union {
    const D3D12DDIARG_STAGE_IO_SIGNATURES        *Standard;
    const D3D12DDIARG_TESSELLATION_IO_SIGNATURES *Tessellation;
    const D3D12DDIARG_MESH_IO_SIGNATURES         *Mesh;
  } IOSignatures;
  D3D12DDI_CREATE_SHADER_FLAGS    Flags;
  D3D12DDI_LIBRARY_REFERENCE_0010 LibraryReference;
  D3D12DDI_SHADERCACHE_HASH       ShaderCodeHash;
} D3D12DDIARG_CREATE_SHADER_0026;