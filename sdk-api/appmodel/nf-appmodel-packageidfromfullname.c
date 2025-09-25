LONG PackageIdFromFullName(
  [in]            PCWSTR       packageFullName,
  [in]            const UINT32 flags,
  [in, out]       UINT32       *bufferLength,
  [out, optional] BYTE         *buffer
);