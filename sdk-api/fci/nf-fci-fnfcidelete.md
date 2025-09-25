## Description

The **FNFCIDELETE** macro provides the declaration for the application-defined callback function to delete a file in the FCI context.

## Parameters

### `fn` [in]

The name of the file to be deleted.

## Remarks

The function accepts parameters similar to [remove](https://msdn.microsoft.com/library/2da4hk1d(VS.80).aspx), with the addition of *err* and *pv*.

## Examples

```cpp
FNFCIDELETE(fnFileDelete)
{
    INT iResult = 0;

    UNREFERENCED_PARAMETER(pv);

    if ( DeleteFileA(pszFile) == FALSE)
    {
        *err = GetLastError();
        iResult = -1;
    }

    return iResult;
}

```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)