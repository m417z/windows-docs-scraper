typedef struct _REQUEST_OPLOCK_INPUT_BUFFER {
  WORD  StructureVersion;
  WORD  StructureLength;
  DWORD RequestedOplockLevel;
  DWORD Flags;
} REQUEST_OPLOCK_INPUT_BUFFER, *PREQUEST_OPLOCK_INPUT_BUFFER;