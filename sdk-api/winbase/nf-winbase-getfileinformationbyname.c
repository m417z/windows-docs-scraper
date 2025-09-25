BOOL GetFileInformationByName(
  PCWSTR                  FileName,
  FILE_INFO_BY_NAME_CLASS FileInformationClass,
  PVOID                   FileInfoBuffer,
  ULONG                   FileInfoBufferSize
);