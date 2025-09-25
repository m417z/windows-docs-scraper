PSAM_PASSWORD_FILTER_ROUTINE PsamPasswordFilterRoutine;

BOOLEAN PsamPasswordFilterRoutine(
  [in] PUNICODE_STRING AccountName,
  [in] PUNICODE_STRING FullName,
  [in] PUNICODE_STRING Password,
  [in] BOOLEAN SetOperation
)
{...}