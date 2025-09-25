typedef struct _NPI_PROVIDER_CHARACTERISTICS {
  USHORT                                   Version;
  USHORT                                   Length;
  PNPI_PROVIDER_ATTACH_CLIENT_FN           ProviderAttachClient;
  PNPI_PROVIDER_DETACH_CLIENT_FN           ProviderDetachClient;
  PNPI_PROVIDER_CLEANUP_BINDING_CONTEXT_FN ProviderCleanupBindingContext;
  NPI_REGISTRATION_INSTANCE                ProviderRegistrationInstance;
} NPI_PROVIDER_CHARACTERISTICS;