typedef struct _PEP_PPM_QUERY_COORDINATED_DEPENDENCY {
  [in]  ULONG                             StateIndex;
  [in]  ULONG                             DependencyIndex;
  [in]  ULONG                             DependencySize;
  [out] ULONG                             DependencySizeUsed;
  [out] POHANDLE                          TargetProcessor;
        PEP_COORDINATED_DEPENDENCY_OPTION Options[ANYSIZE_ARRAY];
} PEP_PPM_QUERY_COORDINATED_DEPENDENCY, *PPEP_PPM_QUERY_COORDINATED_DEPENDENCY;