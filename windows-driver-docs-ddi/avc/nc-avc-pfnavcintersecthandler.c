typedef NTSTATUS ( *PFNAVCINTERSECTHANDLER)(
  _In_      PVOID        Context,
  _In_      ULONG        PinId,
  _In_      PKSDATARANGE CallerDataRange,
  _In_      PKSDATARANGE DescriptorDataRange,
  _In_      ULONG        DataBufferSize,
  _Out_opt_ PVOID        Data,
  _Out_     PULONG       ReportedDataSize
);