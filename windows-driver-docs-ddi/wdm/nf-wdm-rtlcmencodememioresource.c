NTSYSAPI NTSTATUS RtlCmEncodeMemIoResource(
  [in] PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor,
  [in] UCHAR                           Type,
  [in] ULONGLONG                       Length,
  [in] ULONGLONG                       Start
);