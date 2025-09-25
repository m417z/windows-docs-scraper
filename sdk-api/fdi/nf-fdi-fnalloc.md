# FNALLOC macro

## Description

The **FNALLOC** provides the declaration for the application-defined callback function to allocate memory in an FDI context.

## Parameters

### `fn`

The number of bytes to allocate.

## Remarks

The function accepts parameters similar to [malloc](https://msdn.microsoft.com/library/6ewkz86d(VS.80).aspx).

#### Examples

```cpp
FNALLOC(fnMemAlloc)
{
    return malloc(cb);
}

```

## See also

[FNFree](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnfree)