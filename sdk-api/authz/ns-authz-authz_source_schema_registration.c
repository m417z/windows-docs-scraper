typedef struct _AUTHZ_SOURCE_SCHEMA_REGISTRATION {
  DWORD                                      dwFlags;
  PWSTR                                      szEventSourceName;
  PWSTR                                      szEventMessageFile;
  PWSTR                                      szEventSourceXmlSchemaFile;
  PWSTR                                      szEventAccessStringsFile;
  PWSTR                                      szExecutableImagePath;
  union {
    PVOID pReserved;
    GUID  *pProviderGuid;
  } DUMMYUNIONNAME;
  DWORD                                      dwObjectTypeNameCount;
  AUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET ObjectTypeNames[ANYSIZE_ARRAY];
} AUTHZ_SOURCE_SCHEMA_REGISTRATION, *PAUTHZ_SOURCE_SCHEMA_REGISTRATION;