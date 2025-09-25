BOOLEAN RtlIsNameLegalDOS8Dot3(
  [in]                PUNICODE_STRING Name,
  [in, out, optional] POEM_STRING     OemName,
  [out, optional]     PBOOLEAN        NameContainsSpaces
);