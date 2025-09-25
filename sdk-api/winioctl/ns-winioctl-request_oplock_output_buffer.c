typedef struct _REQUEST_OPLOCK_OUTPUT_BUFFER {
  WORD        StructureVersion;
  WORD        StructureLength;
  DWORD       OriginalOplockLevel;
  DWORD       NewOplockLevel;
  DWORD       Flags;
  ACCESS_MASK AccessMode;
  WORD        ShareMode;
} REQUEST_OPLOCK_OUTPUT_BUFFER, *PREQUEST_OPLOCK_OUTPUT_BUFFER;