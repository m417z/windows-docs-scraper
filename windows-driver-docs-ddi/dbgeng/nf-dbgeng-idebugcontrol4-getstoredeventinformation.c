HRESULT GetStoredEventInformation(
  [out]           PULONG Type,
  [out]           PULONG ProcessId,
  [out]           PULONG ThreadId,
  [out, optional] PVOID  Context,
  [in]            ULONG  ContextSize,
  [out, optional] PULONG ContextUsed,
  [out, optional] PVOID  ExtraInformation,
  [in]            ULONG  ExtraInformationSize,
  [out, optional] PULONG ExtraInformationUsed
);