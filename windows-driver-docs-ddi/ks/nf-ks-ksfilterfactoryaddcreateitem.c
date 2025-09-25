KSDDKAPI NTSTATUS KsFilterFactoryAddCreateItem(
  [in]           PKSFILTERFACTORY     FilterFactory,
  [in]           PWSTR                RefString,
  [in, optional] PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]           ULONG                CreateItemFlags
);