typedef struct _D3DKMT_QUERYSTATISTICS {
  D3DKMT_QUERYSTATISTICS_TYPE   Type;
  LUID                          AdapterLuid;
  HANDLE                        hProcess;
  D3DKMT_QUERYSTATISTICS_RESULT QueryResult;
  union {
    D3DKMT_QUERYSTATISTICS_QUERY_SEGMENT                QuerySegment;
    D3DKMT_QUERYSTATISTICS_QUERY_SEGMENT                QueryProcessSegment;
    D3DKMT_MEMORY_SEGMENT_GROUP                         QueryProcessSegmentGroup;
    D3DKMT_QUERYSTATISTICS_QUERY_NODE                   QueryNode;
    D3DKMT_QUERYSTATISTICS_QUERY_NODE                   QueryProcessNode;
    D3DKMT_QUERYSTATISTICS_QUERY_VIDPNSOURCE            QueryVidPnSource;
    D3DKMT_QUERYSTATISTICS_QUERY_VIDPNSOURCE            QueryProcessVidPnSource;
    D3DKMT_QUERYSTATISTICS_QUERY_PHYSICAL_ADAPTER       QueryPhysAdapter;
    D3DKMT_QUERYSTATISTICS_QUERY_ADAPTER2               QueryAdapter2;
    D3DKMT_QUERYSTATISTICS_QUERY_SEGMENT2               QuerySegment2;
    D3DKMT_QUERYSTATISTICS_QUERY_ADAPTER2               QueryProcessAdapter2;
    D3DKMT_QUERYSTATISTICS_QUERY_SEGMENT2               QueryProcessSegment2;
    D3DKMT_QUERYSTATISTICS_QUERY_PROCESS_SEGMENT_GROUP2 QueryProcessSegmentGroup2;
    D3DKMT_QUERYSTATISTICS_QUERY_SEGMENT_USAGE          QuerySegmentUsage;
    D3DKMT_QUERYSTATISTICS_QUERY_SEGMENT_GROUP_USAGE    QuerySegmentGroupUsage;
    D3DKMT_QUERYSTATISTICS_QUERY_NODE2                  QueryNode2;
    D3DKMT_QUERYSTATISTICS_QUERY_NODE2                  QueryProcessNode2;
  };
} D3DKMT_QUERYSTATISTICS;