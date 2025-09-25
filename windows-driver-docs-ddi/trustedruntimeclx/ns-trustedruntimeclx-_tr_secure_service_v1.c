typedef struct _TR_SECURE_SERVICE_V1 {
  ULONG                   DescriptionSize;
  GUID                    ServiceGuid;
  ULONG                   MajorVersion;
  ULONG                   MinorVersion;
  ULONG                   ExtensionOffset;
  ULONG                   CountDependencies;
  TR_SECURE_DEPENDENCY_V1 Dependencies[ANYSIZE_ARRAY];
} TR_SECURE_SERVICE_V1, *PTR_SECURE_SERVICE_V1;