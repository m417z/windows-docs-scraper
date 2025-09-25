## Description

The **FNFCISEEK** macro provides the declaration for the application-defined callback function to move a file pointer to the specified location in an FCI context.

## Parameters

### `fn`

An application-defined value used to identify the open file.

## Remarks

The function accepts parameters similar to [_lseek](https://msdn.microsoft.com/library/ms235323(VS.80).aspx) with the addition to *err* and *pv*.

## Examples

```cpp
FNFCISEEK(fnFileSeek)
{
    INT iResult = 0;

    UNREFERENCED_PARAMETER(pv);

    iResult = SetFilePointer((HANDLE)hf, dist, NULL, seektype);

    if ( iResult == -1 )
    {
        *err = GetLastError();
    }

    return iResult;
}
```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)