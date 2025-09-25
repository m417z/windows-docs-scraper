typedef struct COPYFILE2_EXTENDED_PARAMETERS_V2 {
  DWORD                         dwSize;
  DWORD                         dwCopyFlags;
  BOOL                          *pfCancel;
  PCOPYFILE2_PROGRESS_ROUTINE   pProgressRoutine;
  PVOID                         pvCallbackContext;
  DWORD                         dwCopyFlagsV2;
  ULONG                         ioDesiredSize;
  ULONG                         ioDesiredRate;
  LPPROGRESS_ROUTINE            pProgressRoutineOld;
  PCOPYFILE2_CREATE_OPLOCK_KEYS SourceOplockKeys;
#if ...
  PVOID                         reserved[6];
#elif
  PVOID                         reserved[7];
#else
  PVOID                         reserved[8];
#endif
} COPYFILE2_EXTENDED_PARAMETERS_V2;