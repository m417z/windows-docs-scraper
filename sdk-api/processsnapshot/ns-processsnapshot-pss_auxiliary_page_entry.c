typedef struct {
  void                     *Address;
  MEMORY_BASIC_INFORMATION BasicInformation;
  FILETIME                 CaptureTime;
  void                     *PageContents;
  DWORD                    PageSize;
} PSS_AUXILIARY_PAGE_ENTRY;