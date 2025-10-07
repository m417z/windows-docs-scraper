volatile void* __cdecl
  CopyVolatileMemory (
    _Out_writes_bytes_all_(Length) volatile void* Destination,
    _In_reads_bytes_(Length) volatile const void* Source,
    SIZE_T Length
  );