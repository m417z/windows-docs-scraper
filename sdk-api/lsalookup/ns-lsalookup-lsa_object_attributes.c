typedef struct _LSA_OBJECT_ATTRIBUTES {
  ULONG               Length;
  HANDLE              RootDirectory;
  PLSA_UNICODE_STRING ObjectName;
  ULONG               Attributes;
  PVOID               SecurityDescriptor;
  PVOID               SecurityQualityOfService;
} LSA_OBJECT_ATTRIBUTES, *PLSA_OBJECT_ATTRIBUTES;