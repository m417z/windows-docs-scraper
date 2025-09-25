NTSTATUS FLTAPI FltEnumerateVolumes(
  [in]  PFLT_FILTER Filter,
  [out] PFLT_VOLUME *VolumeList,
  [in]  ULONG       VolumeListSize,
  [out] PULONG      NumberVolumesReturned
);