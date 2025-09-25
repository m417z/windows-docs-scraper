typedef struct D3D12_SHADER_CACHE_SESSION_DESC {
  GUID                     Identifier;
  D3D12_SHADER_CACHE_MODE  Mode;
  D3D12_SHADER_CACHE_FLAGS Flags;
  UINT                     MaximumInMemoryCacheSizeBytes;
  UINT                     MaximumInMemoryCacheEntries;
  UINT                     MaximumValueFileSizeBytes;
  UINT64                   Version;
} D3D12_SHADER_CACHE_SESSION_DESC;