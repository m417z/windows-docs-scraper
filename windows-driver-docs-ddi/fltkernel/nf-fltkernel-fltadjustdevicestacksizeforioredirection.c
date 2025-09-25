NTSTATUS FLTAPI FltAdjustDeviceStackSizeForIoRedirection(
  [in]            PFLT_INSTANCE SourceInstance,
  [in]            PFLT_INSTANCE TargetInstance,
  [out, optional] PBOOLEAN      SourceDeviceStackSizeModified
);