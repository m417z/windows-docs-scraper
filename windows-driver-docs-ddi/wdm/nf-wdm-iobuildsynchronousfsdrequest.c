__drv_aliasesMem PIRP IoBuildSynchronousFsdRequest(
  [in]           ULONG            MajorFunction,
  [in]           PDEVICE_OBJECT   DeviceObject,
  [in, out]      PVOID            Buffer,
  [in, optional] ULONG            Length,
  [in, optional] PLARGE_INTEGER   StartingOffset,
  [in]           PKEVENT          Event,
  [out]          PIO_STATUS_BLOCK IoStatusBlock
);