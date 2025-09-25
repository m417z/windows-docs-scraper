## Description

The **FNFCIREAD** macro provides the declaration for the application-defined callback function to read data from a file in an FCI context.

## Parameters

### `fn`

An application-defined value used to identify the open file.

## Remarks

The function accepts parameters similar to [_read](https://msdn.microsoft.com/library/wyssk1bs(VS.80).aspx) with the addition to *err* and *pv*.

## Examples

```cpp
FNFCIREAD(fnFileRead)
{
    DWORD dwBytesRead = 0;

    UNREFERENCED_PARAMETER(pv);

    if( ReadFile((HANDLE)hf, memory, cb, &dwBytesRead, NULL) == FALSE )
    {
        dwBytesRead = (DWORD)-1;
        *err = GetLastError();
    }

    return dwBytesRead;
}
```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)