NTSTATUS WdfRequestRetrieveOutputBuffer(
  [in]            WDFREQUEST Request,
  [in]            size_t     MinimumRequiredSize,
  [out]           PVOID      *Buffer,
  [out, optional] size_t     *Length
);