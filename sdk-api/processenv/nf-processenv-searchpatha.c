DWORD SearchPathA(
  [in, optional]  LPCSTR lpPath,
  [in]            LPCSTR lpFileName,
  [in, optional]  LPCSTR lpExtension,
  [in]            DWORD  nBufferLength,
  [out]           LPSTR  lpBuffer,
  [out, optional] LPSTR  *lpFilePart
);