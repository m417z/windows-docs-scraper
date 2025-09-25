typedef struct _FILE_FS_ATTRIBUTE_INFORMATION {
  ULONG FileSystemAttributes;
  LONG  MaximumComponentNameLength;
  ULONG FileSystemNameLength;
  WCHAR FileSystemName[1];
} FILE_FS_ATTRIBUTE_INFORMATION, *PFILE_FS_ATTRIBUTE_INFORMATION;