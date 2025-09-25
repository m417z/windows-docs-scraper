HRESULT Read(
  [in]  ULONGLONG offsetFileStart,
  [in]  ULONG     bytesToRead,
  [out] ULONG     *bytesActuallyRead,
  [out] BYTE      *buffer,
  [out] BOOL      *eof
);