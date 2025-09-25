typedef struct {
  ULONG                       CategoriesCount;
  const GUID                  *Categories;
  ULONG                       TopologyNodesCount;
  const GUID                  *TopologyNodes;
  ULONG                       TopologyConnectionsCount;
  const KSTOPOLOGY_CONNECTION *TopologyConnections;
  const GUID                  *TopologyNodesNames;
  ULONG                       Reserved;
} KSTOPOLOGY, *PKSTOPOLOGY;