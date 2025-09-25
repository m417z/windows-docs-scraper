## Description

The **FNFCIOPEN** macro provides the declaration for the application-defined callback function to open a file in an FCI context.

## Parameters

### `fn` [in]

The name of the file.

## Remarks

The function accepts parameters similar to [_open](https://msdn.microsoft.com/library/z0kc8e3z(VS.71).aspx).

## Examples

```cpp
FNFCIOPEN(fnFileOpen)
{
    HANDLE hFile = NULL;
    DWORD dwDesiredAccess = 0;
    DWORD dwCreationDisposition = 0;

    UNREFERENCED_PARAMETER(pv);
    UNREFERENCED_PARAMETER(pmode);

    if ( oflag & _O_RDWR )
    {
        dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
    }
    else if ( oflag & _O_WRONLY )
    {
        dwDesiredAccess = GENERIC_WRITE;
    }
    else
    {
        dwDesiredAccess = GENERIC_READ;
    }

    if ( oflag & _O_CREAT )
    {
        dwCreationDisposition = CREATE_ALWAYS;
    }
    else
    {
        dwCreationDisposition = OPEN_EXISTING;
    }

    hFile = CreateFileA(pszFile,
                        dwDesiredAccess,
                        FILE_SHARE_READ,
                        NULL,
                        dwCreationDisposition,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL);

    if ( hFile == INVALID_HANDLE_VALUE )
    {
        *err = GetLastError();
    }

    return (INT_PTR)hFile;
}

```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)