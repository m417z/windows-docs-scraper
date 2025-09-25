## Description

The **FNFCICLOSE** macro provides the declaration for the application-defined callback function to close a file in an FCI context.

## Parameters

### `fn`

Specifies an application-defined value that identifies an open file.

## Remarks

The function accepts parameters similar to [_close](https://msdn.microsoft.com/library/5fzwd5ss(VS.80).aspx), with the addition of *err* and *pv*.

## Examples

```cpp
FNFCICLOSE(fnFileClose)
{
    INT iResult = 0;

    UNREFERENCED_PARAMETER(pv);

    if ( CloseHandle((HANDLE)hf) == FALSE)
    {
        *err = GetLastError();
        iResult = -1;
    }

    return iResult;
}
```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)