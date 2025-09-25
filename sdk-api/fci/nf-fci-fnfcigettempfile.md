## Description

The **FNFCIGETTEMPFILE** macro provides the declaration for the application-defined callback function to obtain a temporary file name.

## Parameters

### `fn` [out]

Pointer to a buffer to receive the complete temporary file name.

## Remarks

The function can return a filename that already exists by the time it is opened. For this reason, the caller should be prepared to make several attempts to create temporary files.

## Examples

```cpp
FNFCIGETTEMPFILE(fnGetTempFileName)
{
    BOOL bSucceeded = FALSE;
    CHAR pszTempPath[MAX_PATH];
    CHAR pszTempFile[MAX_PATH];

    UNREFERENCED_PARAMETER(pv);
    UNREFERENCED_PARAMETER(cbTempName);

    if( GetTempPathA(MAX_PATH, pszTempPath) != 0 )
    {
        if( GetTempFileNameA(pszTempPath, "CABINET", 0, pszTempFile) != 0 )
        {
            DeleteFileA(pszTempFile);
            bSucceeded = SUCCEEDED(StringCbCopyA(pszTempName, cbTempName, pszTempFile));
        }
    }

    return bSucceeded;
}
```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)