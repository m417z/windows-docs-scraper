NTSTATUS DataRangeIntersection(
  ULONG        PinId,
  PKSDATARANGE DataRange,
  PKSDATARANGE MatchingDataRange,
  ULONG        OutputBufferLength,
  PVOID        ResultantFormat,
  PULONG       ResultantFormatLength
);