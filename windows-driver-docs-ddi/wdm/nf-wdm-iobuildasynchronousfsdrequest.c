__drv_aliasesMem PIRP IoBuildAsynchronousFsdRequest(
  [in]           ULONG            MajorFunction,
  [in]           PDEVICE_OBJECT   DeviceObject,
  [in, out]      PVOID            Buffer,
  [in, optional] ULONG            Length,
  [in, optional] PLARGE_INTEGER   StartingOffset,
  [in, optional] PIO_STATUS_BLOCK IoStatusBlock
);