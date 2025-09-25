BOOL IMAGEAPI ImageEnumerateCertificates(
  [in]           HANDLE FileHandle,
  [in]           WORD   TypeFilter,
  [out]          PDWORD CertificateCount,
  [in, out]      PDWORD Indices,
  [in, optional] DWORD  IndexCount
);