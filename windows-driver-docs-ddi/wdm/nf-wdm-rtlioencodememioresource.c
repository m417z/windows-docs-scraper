NTSYSAPI NTSTATUS RtlIoEncodeMemIoResource(
  [in] PIO_RESOURCE_DESCRIPTOR Descriptor,
  [in] UCHAR                   Type,
  [in] ULONGLONG               Length,
  [in] ULONGLONG               Alignment,
  [in] ULONGLONG               MinimumAddress,
  [in] ULONGLONG               MaximumAddress
);