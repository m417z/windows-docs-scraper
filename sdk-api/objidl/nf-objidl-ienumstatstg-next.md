# IEnumSTATSTG::Next

## Description

The **Next** method retrieves a specified number of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures, that follow in the enumeration sequence. If there are fewer than the requested number of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures that remain in the enumeration sequence, it retrieves the remaining **STATSTG** structures.

## Parameters

### `celt` [in]

The number of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures requested.

### `rgelt` [out]

An array of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures returned.

### `pceltFetched` [out]

The number of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures retrieved in the *rgelt* parameter.

## Return value

This method supports the following return values:

| Return code | Description |
| --- | --- |
| **S_OK** | The number of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures returned is equal to the number specified in the *celt* parameter. |
| **S_FALSE** | The number of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures returned is less than the number specified in the *celt* parameter. |

## See also

[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg)