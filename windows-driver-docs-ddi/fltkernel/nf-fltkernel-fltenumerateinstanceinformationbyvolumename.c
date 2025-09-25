NTSTATUS FLTAPI FltEnumerateInstanceInformationByVolumeName(
  [in]  PUNICODE_STRING            VolumeName,
  [in]  ULONG                      Index,
  [in]  INSTANCE_INFORMATION_CLASS InformationClass,
  [out] PVOID                      Buffer,
  [in]  ULONG                      BufferSize,
  [out] PULONG                     BytesReturned
);