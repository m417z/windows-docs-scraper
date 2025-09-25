NTSTATUS IoPageRead(
  PFILE_OBJECT     FileObject,
  PMDL             MemoryDescriptorList,
  PLARGE_INTEGER   StartingOffset,
  PKEVENT          Event,
  PIO_STATUS_BLOCK IoStatusBlock
);