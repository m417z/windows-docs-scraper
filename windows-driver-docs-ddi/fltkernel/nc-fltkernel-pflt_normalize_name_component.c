PFLT_NORMALIZE_NAME_COMPONENT PfltNormalizeNameComponent;

NTSTATUS PfltNormalizeNameComponent(
  [in]      PFLT_INSTANCE Instance,
  [in]      PCUNICODE_STRING ParentDirectory,
  [in]      USHORT VolumeNameLength,
  [in]      PCUNICODE_STRING Component,
  [out]     PFILE_NAMES_INFORMATION ExpandComponentName,
  [in]      ULONG ExpandComponentNameLength,
  [in]      FLT_NORMALIZE_NAME_FLAGS Flags,
  [in, out] PVOID *NormalizationContext
)
{...}