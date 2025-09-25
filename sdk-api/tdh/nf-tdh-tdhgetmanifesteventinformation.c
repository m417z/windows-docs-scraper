TDHSTATUS TdhGetManifestEventInformation(
  [in]      LPGUID            ProviderGuid,
  [in]      PEVENT_DESCRIPTOR EventDescriptor,
  [out]     PTRACE_EVENT_INFO Buffer,
  [in, out] ULONG             *BufferSize
);