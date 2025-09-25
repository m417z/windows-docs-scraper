typedef struct D3D12_QUERY_DATA_PIPELINE_STATISTICS1 {
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
  UINT64 ASInvocations;
  UINT64 MSInvocations;
  UINT64 MSPrimitives;
} D3D12_QUERY_DATA_PIPELINE_STATISTICS1;