DUMP_WRITE DumpWrite;

NTSTATUS DumpWrite(
  [in]      PFILTER_EXTENSION FilterExtension,
  [in, out] PLARGE_INTEGER DiskByteOffset,
  [in, out] PMDL Mdl
)
{...}