TAPE_ERROR_ROUTINE TapeErrorRoutine;

VOID TapeErrorRoutine(
  [in]      PVOID MinitapeExtension,
  [in]      PSCSI_REQUEST_BLOCK Srb,
  [in, out] PTAPE_STATUS TapeStatus
)
{...}