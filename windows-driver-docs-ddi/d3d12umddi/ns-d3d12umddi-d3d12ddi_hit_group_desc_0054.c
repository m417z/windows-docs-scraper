typedef struct D3D12DDI_HIT_GROUP_DESC_0054 {
  LPCWSTR                       HitGroupExport;
  D3D12DDI_HIT_GROUP_TYPE       Type;
  LPCWSTR                       AnyHitShaderImport;
  LPCWSTR                       ClosestHitShaderImport;
  LPCWSTR                       IntersectionShaderImport;
  D3D12DDI_EXPORT_SUMMARY_FLAGS SummaryFlags;
} D3D12DDI_HIT_GROUP_DESC_0054;