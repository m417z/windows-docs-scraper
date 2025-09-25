PORTCLASSAPI NTSTATUS PcForwardContentToDeviceObject(
  [in]           ULONG        ContentId,
  [in, optional] PVOID        Reserved,
  [in]           PCDRMFORWARD DrmForward
);