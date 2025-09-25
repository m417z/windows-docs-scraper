PI8042_SYNCH_READ_PORT Pi8042SynchReadPort;

NTSTATUS Pi8042SynchReadPort(
  [in]  PVOID Context,
  [out] PUCHAR Value,
  [in]  BOOLEAN WaitForACK
)
{...}