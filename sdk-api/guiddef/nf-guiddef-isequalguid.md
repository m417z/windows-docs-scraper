## Description

Evaluates to a Boolean value that indicates whether two GUIDs are equal.

## Syntax

```cpp
BOOL IsEqualGUID(
  rguid1,
  rguid2
);
```

## Parameters

### `rguid1`

The first GUID.

### `rguid2`

The second GUID.

## Return value

`TRUE` if the two GUIDs are equal; otherwise, `FALSE`.

## Remarks

**IsEqualGUID** is used by the [IsEqualCLSID](https://learn.microsoft.com/windows/win32/api/guiddef/nf-guiddef-isequalclsid) and [IsEqualIID](https://learn.microsoft.com/windows/win32/api/guiddef/nf-guiddef-isequaliid) macros.

## See also

* [IsEqualCLSID](https://learn.microsoft.com/windows/win32/api/guiddef/nf-guiddef-isequalclsid)
* [IsEqualIID](https://learn.microsoft.com/windows/win32/api/guiddef/nf-guiddef-isequaliid)