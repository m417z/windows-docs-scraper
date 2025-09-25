typedef struct _NDIS_PD_OPEN_PROVIDER_PARAMETERS {
  NDIS_OBJECT_HEADER              Header;
  ULONG                           Flags;
  NDIS_PD_PROVIDER_HANDLE         ProviderHandle;
  const NDIS_PD_PROVIDER_DISPATCH *ProviderDispatch;
} NDIS_PD_OPEN_PROVIDER_PARAMETERS;