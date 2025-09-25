HRESULT GetLastEventInformation(
  [out]           PULONG Type,
  [out]           PULONG ProcessId,
  [out]           PULONG ThreadId,
  [out, optional] PVOID  ExtraInformation,
  [in]            ULONG  ExtraInformationSize,
  [out, optional] PULONG ExtraInformationUsed,
  [out, optional] PSTR   Description,
  [in]            ULONG  DescriptionSize,
  [out, optional] PULONG DescriptionUsed
);