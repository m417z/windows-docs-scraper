PI8042_SYNCH_WRITE_PORT Pi8042SynchWritePort;

NTSTATUS Pi8042SynchWritePort(
  [in] PVOID Context,
  [in] UCHAR Value,
  [in] BOOLEAN WaitForACK
)
{...}