_WHEA_ERROR_SOURCE_CREATE_RECORD WheaErrorSourceCreateRecord;

NTSTATUS WheaErrorSourceCreateRecord(
  PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource,
  PWHEA_ERROR_PACKET ErrorPacket,
  PWHEA_ERROR_RECORD ErrorRecord,
  ULONG BufferSize,
  PVOID Context
)
{...}