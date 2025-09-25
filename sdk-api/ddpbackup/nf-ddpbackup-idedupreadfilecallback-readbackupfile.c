HRESULT ReadBackupFile(
  [in]  BSTR  FileFullPath,
  [in]  hyper FileOffset,
  [in]  ULONG SizeToRead,
  [out] BYTE  *FileBuffer,
  [out] ULONG *ReturnedSize,
  [in]  DWORD Flags
);