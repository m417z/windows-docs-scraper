BOOL IMAGEAPI ImageGetCertificateData(
  [in]      HANDLE            FileHandle,
  [in]      DWORD             CertificateIndex,
  [out]     LPWIN_CERTIFICATE Certificate,
  [in, out] PDWORD            RequiredLength
);