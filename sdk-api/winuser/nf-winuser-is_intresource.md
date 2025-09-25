# IS_INTRESOURCE macro

## Syntax

```cpp
BOOL IS_INTRESOURCE(
    void *_r
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the value is a resource identifier, the return value is **TRUE**. Otherwise, the return value is **FALSE**.

## Description

Determines whether a value is an integer identifier for a resource.

## Parameters

### `_r`

The pointer to be tested whether it contains an integer resource identifier.

## Remarks

This macro checks whether all bits except the least 16 bits are zero. When true, *_r* is an integer identifier for a resource. Otherwise it is typically a pointer to a string.

## See also

[Resources Overview](https://learn.microsoft.com/windows/desktop/menurc/resources)