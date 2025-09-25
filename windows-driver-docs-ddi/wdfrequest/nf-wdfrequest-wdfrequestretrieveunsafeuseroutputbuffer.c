NTSTATUS WdfRequestRetrieveUnsafeUserOutputBuffer(
  [in]            WDFREQUEST Request,
  [in]            size_t     MinimumRequiredLength,
  [out]           PVOID      *OutputBuffer,
  [out, optional] size_t     *Length
);