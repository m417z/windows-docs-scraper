PSHED_PI_READ_ERROR_RECORD PshedPiReadErrorRecord;

NTSTATUS PshedPiReadErrorRecord(
  [in, out, optional] PVOID PluginContext,
  [in]                ULONG Flags,
  [in]                ULONGLONG ErrorRecordId,
  [out]               PULONGLONG NextErrorRecordId,
  [in, out]           PULONG RecordLength,
  [out]               PWHEA_ERROR_RECORD ErrorRecord
)
{...}