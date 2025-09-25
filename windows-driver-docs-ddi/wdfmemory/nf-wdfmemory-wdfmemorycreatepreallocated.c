NTSTATUS WdfMemoryCreatePreallocated(
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [in]           __drv_aliasesMem PVOID Buffer,
  [in]           size_t                 BufferSize,
  [out]          WDFMEMORY              *Memory
);