NTSTATUS FLTAPI FltGetVolumeProperties(
  [in]  PFLT_VOLUME            Volume,
  [out] PFLT_VOLUME_PROPERTIES VolumeProperties,
        ULONG                  VolumePropertiesLength,
  [out] PULONG                 LengthReturned
);