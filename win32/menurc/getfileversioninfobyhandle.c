BOOL GetFileVersionInfoByHandle(
    __in                        DWORD    dwFlags,
    __in                        HANDLE   hFile,
    __deref_out_bcount(*pdwLen) LPVOID * lplpData,
    __out                       PDWORD   pdwLen
    )