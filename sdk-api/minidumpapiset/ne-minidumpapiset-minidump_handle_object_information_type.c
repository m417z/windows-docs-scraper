typedef enum _MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE {
  MiniHandleObjectInformationNone,
  MiniThreadInformation1,
  MiniMutantInformation1,
  MiniMutantInformation2,
  MiniProcessInformation1,
  MiniProcessInformation2,
  MiniEventInformation1,
  MiniSectionInformation1,
  MiniSemaphoreInformation1,
  MiniHandleObjectInformationTypeMax
} MINIDUMP_HANDLE_OBJECT_INFORMATION_TYPE;