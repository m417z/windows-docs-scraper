BOOL HeapSetInformation(
  [in, optional] HANDLE                 HeapHandle,
  [in]           HEAP_INFORMATION_CLASS HeapInformationClass,
  [in]           PVOID                  HeapInformation,
  [in]           SIZE_T                 HeapInformationLength
);