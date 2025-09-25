typedef struct _PEP_QUERY_SOC_SUBSYSTEM_METADATA {
  [in]     ULONG                       PlatformIdleStateIndex;
  [in]     PVOID                       SubsystemHandle;
  [in]     PCUNICODE_STRING            SubsystemName;
           ULONG                       Flags;
  [in]     ULONG                       MetadataCount;
           PPEP_SOC_SUBSYSTEM_METADATA Metadata[ANYSIZE_ARRAY];
} PEP_QUERY_SOC_SUBSYSTEM_METADATA, *PPEP_QUERY_SOC_SUBSYSTEM_METADATA;