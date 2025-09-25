typedef struct D3D12_QUERY_DATA_PIPELINE_STATISTICS {
  UINT64 IAVertices;
  UINT64 IAPrimitives;
  UINT64 VSInvocations;
  UINT64 GSInvocations;
  UINT64 GSPrimitives;
  UINT64 CInvocations;
  UINT64 CPrimitives;
  UINT64 PSInvocations;
  UINT64 HSInvocations;
  UINT64 DSInvocations;
  UINT64 CSInvocations;
} D3D12_QUERY_DATA_PIPELINE_STATISTICS;