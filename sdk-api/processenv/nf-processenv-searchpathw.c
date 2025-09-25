DWORD SearchPathW(
  [in, optional]  LPCWSTR lpPath,
  [in]            LPCWSTR lpFileName,
  [in, optional]  LPCWSTR lpExtension,
  [in]            DWORD   nBufferLength,
  [out]           LPWSTR  lpBuffer,
  [out, optional] LPWSTR  *lpFilePart
);