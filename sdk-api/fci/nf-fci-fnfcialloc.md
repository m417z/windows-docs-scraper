# FNFCIALLOC macro

## Description

The **FNFCIALLOC** provides the declaration for the application-defined callback function to allocate memory within an FCI context.

## Parameters

### `fn`

The number of bytes to allocate.

## Remarks

The function accepts parameters similar to [malloc](https://msdn.microsoft.com/library/6ewkz86d(VS.80).aspx).

#### Examples

```cpp
FNFCIALLOC(fnMemAlloc)
{
    return malloc(cb);
}

```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)