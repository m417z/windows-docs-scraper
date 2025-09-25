## Description

The **FNREAD** macro provides the declaration for the application-defined callback function to read data from a file in an FDI context.

## Parameters

### `fn` [in]

An application-defined value used to identify the open file.

## Remarks

The function accepts parameters similar to [_read](https://msdn.microsoft.com/library/wyssk1bs(VS.80).aspx).

## Examples

```cpp
FNREAD(fnFileRead)
{
    DWORD dwBytesRead = 0;

    if ( ReadFile((HANDLE)hf, pv, cb, &dwBytesRead, NULL) == FALSE )
    {
        dwBytesRead = (DWORD)-1L;
    }

    return dwBytesRead;
}
```

## See also

[FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate)