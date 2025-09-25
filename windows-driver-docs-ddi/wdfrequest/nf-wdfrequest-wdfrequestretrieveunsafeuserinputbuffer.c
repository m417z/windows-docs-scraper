NTSTATUS WdfRequestRetrieveUnsafeUserInputBuffer(
  [in]            WDFREQUEST Request,
  [in]            size_t     MinimumRequiredLength,
  [out]           PVOID      *InputBuffer,
  [out, optional] size_t     *Length
);