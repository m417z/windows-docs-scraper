PFN_WSK_CLIENT_EVENT PfnWskClientEvent;

NTSTATUS PfnWskClientEvent(
  [in, optional] PVOID ClientContext,
  [in]           ULONG EventType,
  [in, optional] PVOID Information,
  [in]           SIZE_T InformationLength
)
{...}