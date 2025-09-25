NTSTATUS WdfRequestRetrieveInputBuffer(
  [in]            WDFREQUEST Request,
                  size_t     MinimumRequiredLength,
  [out]           PVOID      *Buffer,
  [out, optional] size_t     *Length
);