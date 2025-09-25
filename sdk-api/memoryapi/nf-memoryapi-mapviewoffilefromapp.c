PVOID MapViewOfFileFromApp(
  [in] HANDLE  hFileMappingObject,
  [in] ULONG   DesiredAccess,
  [in] ULONG64 FileOffset,
  [in] SIZE_T  NumberOfBytesToMap
);