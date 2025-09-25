## Description

The **FNWRITE** macro provides the declaration for the application-defined callback function to write data to a file in an FDI context.

## Parameters

### `fn` [in]

An application-defined value used to identify the open file.

## Remarks

The function accepts parameters similar to [_write](https://msdn.microsoft.com/library/1570wh78(VS.80).aspx).

## Examples

```cpp
FNWRITE(fnFileWrite)
{
    DWORD dwBytesWritten = 0;

    if ( WriteFile((HANDLE)hf, pv, cb, &dwBytesWritten, NULL) == FALSE )
    {
        dwBytesWritten = (DWORD)-1;
    }

    return dwBytesWritten;
}
```

## See also

[FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate)