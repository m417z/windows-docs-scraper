# ITypeInfo::GetDocumentation

## Description

Retrieves the documentation string, the complete Help file name and path, and the context ID for the Help topic for a specified type description.

## Parameters

### `memid` [in]

The ID of the member whose documentation is to be returned.

### `pBstrName` [out]

The name of the specified item. If the caller does not need the item name, *pBstrName* can be null.

### `pBstrDocString` [out]

The documentation string for the specified item. If the caller does not need the documentation string, *pBstrDocString* can be null.

### `pdwHelpContext` [out]

The Help localization context. If the caller does not need the Help context, it can be null.

### `pBstrHelpFile` [out]

The fully qualified name of the file containing the DLL used for Help file. If the caller does not need the file name, it can be null.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The function **GetDocumentation** provides access to the documentation for the member specified by the *memid* parameter. If the passed-in *memid* is MEMBERID_NIL, then the documentation for the type description is returned.

If the type description inherits from another type description, this function is recursive to the base type description, if necessary, to find the item with the requested member ID.

The caller should use [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the BSTRs referenced by *pBstrName*, *pBstrDocString*, and *pBstrHelpFile*.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)