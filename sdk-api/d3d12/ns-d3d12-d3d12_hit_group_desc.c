typedef struct D3D12_HIT_GROUP_DESC {
  LPCWSTR              HitGroupExport;
  D3D12_HIT_GROUP_TYPE Type;
  LPCWSTR              AnyHitShaderImport;
  LPCWSTR              ClosestHitShaderImport;
  LPCWSTR              IntersectionShaderImport;
} D3D12_HIT_GROUP_DESC;