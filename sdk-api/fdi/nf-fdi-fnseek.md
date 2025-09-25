## Description

The **FNSEEK** macro provides the declaration for the application-defined callback function to move a file pointer to the specified location in an FDI context.

## Parameters

### `fn` [in]

An application-defined value used to identify the open file.

## Remarks

The function accepts parameters similar to [_lseek](https://msdn.microsoft.com/library/ms235323(VS.80).aspx).

## Examples

```cpp
FNSEEK(fnFileSeek)
{
    return SetFilePointer((HANDLE)hf, dist, NULL, seektype);
}
```

## See also

[FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate)