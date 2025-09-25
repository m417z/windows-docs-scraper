HRESULT OrderContainersRestore(
  [in]  ULONG                  NumberOfContainers,
  [in]  BSTR                   *ContainerPaths,
  [out] ULONG                  *ReadPlanEntries,
  [out] DEDUP_CONTAINER_EXTENT **ReadPlan
);