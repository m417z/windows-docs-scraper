typedef struct _EXTENDED_CREATE_INFORMATION {
  LONGLONG                          ExtendedCreateFlags;
  PVOID                             EaBuffer;
  ULONG                             EaLength;
  PEXTENDED_CREATE_DUAL_OPLOCK_KEYS DualOplockKeys;
} EXTENDED_CREATE_INFORMATION, *PEXTENDED_CREATE_INFORMATION;