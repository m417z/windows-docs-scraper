typedef struct _ENCRYPTION_KEY_CTRL_INPUT {
  ULONG     HeaderSize;
  ULONG     StructureSize;
  USHORT    KeyOffset;
  USHORT    KeySize;
  ULONG     DplLock;
  ULONGLONG DplUserId;
  ULONGLONG DplCredentialId;
} ENCRYPTION_KEY_CTRL_INPUT, *PENCRYPTION_KEY_CTRL_INPUT;