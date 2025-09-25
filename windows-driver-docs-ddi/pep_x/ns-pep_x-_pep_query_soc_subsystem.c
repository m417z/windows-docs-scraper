typedef struct _PEP_QUERY_SOC_SUBSYSTEM {
  [in]     ULONG          PlatformIdleStateIndex;
  [in]     ULONG          SubsystemIndex;
  [out]    PVOID          SubsystemHandle;
  [in/out] UNICODE_STRING ParentName;
  [in/out] UNICODE_STRING SubsystemName;
  [out]    ULONG          MetadataCount;
           ULONG          Flags;
} PEP_QUERY_SOC_SUBSYSTEM, *PPEP_QUERY_SOC_SUBSYSTEM;