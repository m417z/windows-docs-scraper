# IEnumVARIANT::Skip

## Description

Attempts to skip over the next celt elements in the enumeration sequence.

## Parameters

### `celt` [in]

The number of elements to skip.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified number of elements was skipped. |
| **S_FALSE** | The end of the sequence was reached before skipping the requested number of elements. |

## See also

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)