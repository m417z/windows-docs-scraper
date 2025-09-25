typedef struct _MSiSCSI_TargetMappings {
  ULONGLONG           UniqueAdapterId;
  ULONG               TargetMappingCount;
  ULONG               Reserved;
  ISCSI_TargetMapping TargetMappings[1];
} MSiSCSI_TargetMappings, *PMSiSCSI_TargetMappings;