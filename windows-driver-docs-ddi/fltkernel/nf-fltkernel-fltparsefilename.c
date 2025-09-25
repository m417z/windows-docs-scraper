NTSTATUS FLTAPI FltParseFileName(
  [in]      PCUNICODE_STRING FileName,
  [in, out] PUNICODE_STRING  Extension,
  [in, out] PUNICODE_STRING  Stream,
  [in, out] PUNICODE_STRING  FinalComponent
);