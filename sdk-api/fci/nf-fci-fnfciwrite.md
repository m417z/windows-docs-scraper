## Description

The **FNFCIWRITE** macro provides the declaration for the application-defined callback function to write data to a file in an FCI context.

## Parameters

### `fn`

An application-defined value used to identify the open file.

## Remarks

The function accepts parameters similar to [_write](https://msdn.microsoft.com/library/1570wh78(VS.80).aspx).

## Examples

```cpp
FNFCIWRITE(fnFileWrite)
{
    DWORD dwBytesWritten = 0;

    UNREFERENCED_PARAMETER(pv);

    if ( WriteFile((HANDLE)hf, memory, cb, &dwBytesWritten, NULL) == FALSE )
    {
        dwBytesWritten = (DWORD)-1;
        *err = GetLastError();
    }

    return dwBytesWritten;
}
```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)