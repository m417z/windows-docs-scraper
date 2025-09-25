DUMP_READ DumpRead;

NTSTATUS DumpRead(
  [in] PFILTER_EXTENSION FilterExtension,
  [in] PLARGE_INTEGER DiskByteOffset,
  [in] PMDL Mdl
)
{...}