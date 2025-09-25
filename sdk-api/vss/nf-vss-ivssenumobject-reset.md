# IVssEnumObject::Reset

## Description

The **Reset** method resets the enumerator
so that [IVssEnumObject:Next](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssenumobject-next) starts at the first
enumerated object.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_FAIL** | There was an internal error in the enumerator. |

## See also

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)

[IVssEnumObject:Next](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssenumobject-next)