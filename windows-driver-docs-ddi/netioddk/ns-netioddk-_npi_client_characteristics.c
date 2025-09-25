typedef struct _NPI_CLIENT_CHARACTERISTICS {
  USHORT                                 Version;
  USHORT                                 Length;
  PNPI_CLIENT_ATTACH_PROVIDER_FN         ClientAttachProvider;
  PNPI_CLIENT_DETACH_PROVIDER_FN         ClientDetachProvider;
  PNPI_CLIENT_CLEANUP_BINDING_CONTEXT_FN ClientCleanupBindingContext;
  NPI_REGISTRATION_INSTANCE              ClientRegistrationInstance;
} NPI_CLIENT_CHARACTERISTICS;