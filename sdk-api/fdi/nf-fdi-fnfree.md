# FNFREE macro

## Description

The **FNFREE** macro provides the declaration for the application-defined callback function to free previously allocated memory in an FDI context.

## Parameters

### `fn` [in, optional]

Pointer to the allocated memory block to free.

## Remarks

The function accepts parameters similar to [free](https://msdn.microsoft.com/library/we1whae7(VS.80).aspx).

#### Examples

```cpp
FNFREE(fnMemFree)
{
    free(pv);
}

```

## See also

[FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate)