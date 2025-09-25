GET_UPDATED_BUS_RESOURCE GetUpdatedBusResource;

NTSTATUS GetUpdatedBusResource(
  [In]  PVOID Context,
  [Out] PCM_RESOURCE_LIST *UpdatedResourceList,
  [Out] PCM_RESOURCE_LIST *UpdatedTranslatedResourceList
)
{...}