typedef struct _STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR {
  DWORD                      Version;
  DWORD                      Size;
  DWORD                      NodeCount;
  DWORD                      Reserved;
  STORAGE_PHYSICAL_NODE_DATA Node[ANYSIZE_ARRAY];
} STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR, *PSTORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR;