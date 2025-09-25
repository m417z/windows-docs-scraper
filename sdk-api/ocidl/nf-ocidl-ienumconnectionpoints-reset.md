# IEnumConnectionPoints::Reset

## Description

Resets the enumeration sequence to the beginning.

## Return value

The return value is S_OK.

## Remarks

There is no guarantee that the same set of objects will be enumerated after the reset operation has completed. A static collection is reset to the beginning, but it can be too expensive for some collections, such as files in a directory, to guarantee this condition.

## See also

[IEnumConnectionPoints](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumconnectionpoints)