# SfcGetNextProtectedFile function

## Description

[This function is available for use in the operating systems specified in the Requirements section. Support for this function was removed in Windows Vista and Windows Server 2008. Use the supported functions listed in [WRP Functions](https://learn.microsoft.com/windows/desktop/Wfp/wfp-functions) instead.]

Retrieves the complete list of protected files. Applications should not replace these files.

## Parameters

### `RpcHandle` [in]

This parameter must be **NULL**.

### `ProtFileData` [in, out]

The list of protected files. The format of this structure is as follows.

``` syntax
typedef struct _PROTECTED_FILE_DATA {
    WCHAR   FileName[MAX_PATH];
    DWORD   FileNumber;
} PROTECTED_FILE_DATA, *PPROTECTED_FILE_DATA;
```

Before calling this function the first time, set the **FileNumber** member to zero.

## Return value

If the function succeeds, the return value is nonzero.

If there are no more protected files to enumerate, the return value is zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_MORE_FILES. If the function fails, **GetLastError** will return a different error code.

## See also

[SfcIsFileProtected](https://learn.microsoft.com/windows/desktop/api/sfc/nf-sfc-sfcisfileprotected)