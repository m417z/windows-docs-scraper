# IVssEnumObject::Skip

## Description

The **Skip** method skips the specified
number of objects.

## Parameters

### `celt` [in]

Number of elements to be skipped in the list of enumerated objects.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **S_FALSE** | An attempt was made to access a location beyond the end of the list of items. |
| **E_FAIL** | There was an internal error in the enumerator. |

## See also

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)