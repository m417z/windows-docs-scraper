HRESULT GetClusterMetrics(
  [out, optional] DWRITE_CLUSTER_METRICS *clusterMetrics,
                  UINT32                 maxClusterCount,
  [out]           UINT32                 *actualClusterCount
);