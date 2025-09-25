typedef struct COPYFILE2_EXTENDED_PARAMETERS {
  DWORD                       dwSize;
  DWORD                       dwCopyFlags;
  BOOL                        *pfCancel;
  PCOPYFILE2_PROGRESS_ROUTINE pProgressRoutine;
  PVOID                       pvCallbackContext;
} COPYFILE2_EXTENDED_PARAMETERS;