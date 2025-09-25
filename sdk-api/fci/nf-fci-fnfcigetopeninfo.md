## Description

The **FNFCIGETOPENINFO** macro provides the declaration for the application-defined callback function to open a file and retrieve file date, time, and attribute.

## Parameters

### `fn` [in]

The complete filename.

## Remarks

The function should open the file using the file open function compatible with those passed into [FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate).

## Examples

```cpp
FNFCIGETOPENINFO(fnGetOpenInfo)
{
    HANDLE hFile;
    FILETIME fileTime;
    BY_HANDLE_FILE_INFORMATION fileInfo;

    hFile = (HANDLE)fnFileOpen(pszName, _O_RDONLY, 0, err, pv);

    if ( hFile != (HANDLE)-1 )
    {
        if( GetFileInformationByHandle(hFile, &fileInfo)
        &&  FileTimeToLocalFileTime(&fileInfo.ftCreationTime, &fileTime)
        &&  FileTimeToDosDateTime(&fileTime, pdate, ptime) )
        {
            *pattribs = (USHORT)fileInfo.dwFileAttributes;
            *pattribs &= ( _A_RDONLY | _A_HIDDEN | _A_SYSTEM | _A_ARCH );
        }
        else
        {
            fnFileClose((INT_PTR)hFile, err, pv);
            hFile = (HANDLE)-1;
        }
    }

    return (INT_PTR)hFile;
}
```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)