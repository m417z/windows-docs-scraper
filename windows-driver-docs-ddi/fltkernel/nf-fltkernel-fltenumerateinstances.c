NTSTATUS FLTAPI FltEnumerateInstances(
  [in, optional] PFLT_VOLUME   Volume,
  [in, optional] PFLT_FILTER   Filter,
  [out]          PFLT_INSTANCE *InstanceList,
  [in]           ULONG         InstanceListSize,
  [out]          PULONG        NumberInstancesReturned
);