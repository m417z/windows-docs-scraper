typedef struct _OPLOCK_KEY_CONTEXT {
  USHORT Version;
  USHORT Flags;
  GUID   ParentOplockKey;
  GUID   TargetOplockKey;
  ULONG  Reserved;
} OPLOCK_KEY_CONTEXT, *POPLOCK_KEY_CONTEXT;