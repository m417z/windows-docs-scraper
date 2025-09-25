# IGroupPolicyObject::GetPropertySheetPages

## Description

The
**GetPropertySheetPages** method retrieves the property sheet pages associated with the GPO.

## Parameters

### `hPages` [out]

Address of the pointer to an array of property sheet pages.

### `uPageCount` [out]

Receives the number of pages in the property sheet array.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

This method allocates memory for the array with the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function. When you are finished with the property sheet pages, free the array using the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## See also

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)