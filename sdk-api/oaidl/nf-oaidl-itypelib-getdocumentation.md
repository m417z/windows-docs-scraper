# ITypeLib::GetDocumentation

## Description

Retrieves the documentation string for the library, the complete Help file name and path, and the context identifier for the library Help topic in the Help file.

## Parameters

### `index` [in]

The index of the type description whose documentation is to be returned. If *index* is -1, then the documentation for the library itself is returned.

### `pBstrName` [out]

The name of the specified item. If the caller does not need the item name, then *pBstrName* can be null.

### `pBstrDocString` [out]

The documentation string for the specified item. If the caller does not need the documentation string, then *pBstrDocString* can be null..

### `pdwHelpContext` [out]

The Help context identifier (ID) associated with the specified item. If the caller does not need the Help context ID, then *pdwHelpContext* can be null.

### `pBstrHelpFile` [out]

 The fully qualified name of the Help file. If the caller does not need the Help file name, then *pBstrHelpFile* can be null.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The caller should free the parameters *pBstrName*, *pBstrDocString*, and *pBstrHelpFile*.

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)