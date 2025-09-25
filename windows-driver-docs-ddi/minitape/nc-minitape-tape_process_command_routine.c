TAPE_PROCESS_COMMAND_ROUTINE TapeProcessCommandRoutine;

TAPE_STATUS TapeProcessCommandRoutine(
  [in, out]      PVOID MinitapeExtension,
  [in, out]      PVOID CommandExtension,
  [in, out]      PVOID CommandParameters,
  [in, out]      PSCSI_REQUEST_BLOCK Srb,
  [in]           ULONG CallNumber,
  [in, optional] TAPE_STATUS StatusOfLastCommand,
  [in, out]      PULONG RetryFlags
)
{...}