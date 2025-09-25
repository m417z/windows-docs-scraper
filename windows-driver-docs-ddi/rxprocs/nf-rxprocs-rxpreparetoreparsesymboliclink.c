NTSTATUS RxPrepareToReparseSymbolicLink(
  PRX_CONTEXT     RxContext,
  BOOLEAN         SymbolicLinkEmbeddedInOldPath,
  PUNICODE_STRING NewPath,
  BOOLEAN         NewPathIsAbsolute,
  PBOOLEAN        ReparseRequired
);