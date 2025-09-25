# FNFCIFREE macro

## Description

The **FNFCIFREE** macro provides the declaration for the application-defined callback function to free previously allocated memory in an FCI context.

## Parameters

### `fn`

Pointer to the allocated memory block to free.

## Remarks

The function accepts parameters similar to [free](https://msdn.microsoft.com/library/we1whae7(VS.80).aspx).

#### Examples

```cpp
FNFCIFREE(fnMemFree)
{
    free(memory);
}

```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)