KSDDKAPI NTSTATUS KsAddObjectCreateItemToObjectHeader(
  [in]           KSOBJECT_HEADER      Header,
  [in]           PDRIVER_DISPATCH     Create,
  [in]           PVOID                Context,
  [in]           PWSTR                ObjectClass,
  [in, optional] PSECURITY_DESCRIPTOR SecurityDescriptor
);