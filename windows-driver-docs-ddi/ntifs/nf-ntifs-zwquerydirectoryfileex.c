NTSYSAPI NTSTATUS ZwQueryDirectoryFileEx(
  [in]           HANDLE                 FileHandle,
  [in, optional] HANDLE                 Event,
  [in, optional] PIO_APC_ROUTINE        ApcRoutine,
  [in, optional] PVOID                  ApcContext,
  [out]          PIO_STATUS_BLOCK       IoStatusBlock,
  [out]          PVOID                  FileInformation,
  [in]           ULONG                  Length,
  [in]           FILE_INFORMATION_CLASS FileInformationClass,
  [in]           ULONG                  QueryFlags,
  [in, optional] PUNICODE_STRING        FileName
);