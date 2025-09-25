typedef struct _EXTENDED_CREATE_INFORMATION_32 {
  LONGLONG                                     ExtendedCreateFlags;
  void POINTER_32                                         *EaBuffer;
  ULONG                                        EaLength;
  PEXTENDED_CREATE_DUAL_OPLOCK_KEYS POINTER_32 DualOplockKeys;
} EXTENDED_CREATE_INFORMATION_32, *PEXTENDED_CREATE_INFORMATION_32;