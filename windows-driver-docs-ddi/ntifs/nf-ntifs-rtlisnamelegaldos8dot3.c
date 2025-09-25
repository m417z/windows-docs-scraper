NTSYSAPI BOOLEAN RtlIsNameLegalDOS8Dot3(
  [in]            PCUNICODE_STRING Name,
  [in, out]       POEM_STRING      OemName,
  [out, optional] PBOOLEAN         NameContainsSpaces
);