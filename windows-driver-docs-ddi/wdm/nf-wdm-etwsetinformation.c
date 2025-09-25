NTSTATUS EtwSetInformation(
  [in]           REGHANDLE        RegHandle,
  [in]           EVENT_INFO_CLASS InformationClass,
  [in, optional] PVOID            EventInformation,
  [in]           ULONG            InformationLength
);