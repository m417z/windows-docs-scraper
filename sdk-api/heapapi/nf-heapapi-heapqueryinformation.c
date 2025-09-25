BOOL HeapQueryInformation(
  [in, optional]  HANDLE                 HeapHandle,
  [in]            HEAP_INFORMATION_CLASS HeapInformationClass,
  [out]           PVOID                  HeapInformation,
  [in]            SIZE_T                 HeapInformationLength,
  [out, optional] PSIZE_T                ReturnLength
);