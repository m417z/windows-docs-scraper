# ITypeInfo2::GetDocumentation2

## Description

Retrieves the documentation string, the complete Help file name and path, the localization context to use, and the context ID for the library Help topic in the Help file.

## Parameters

### `memid` [in]

The member identifier for the type description.

### `lcid` [in]

The locale identifier.

### `pbstrHelpString` [out]

The name of the specified item. If the caller does not need the item name, then *pbstrHelpString* can be null.

### `pdwHelpStringContext` [out]

The Help localization context. If the caller does not need the Help context, it can be null.

### `pbstrHelpStringDll` [out]

The fully qualified name of the file containing the DLL used for Help file. If the caller does not need the file name, it can be null.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

Gets information at the type information level (about the type information and its members). The caller should free the BSTR parameters.

This function will call **_DLLGetDocumentation** in the specified DLL to retrieve the desired Help string, if there is a Help string context for this item. If no Help string context exists or an error occurs, then it will defer to the [GetDocumentation](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-getdocumentation) method and return the associated documentation string.

## See also

[ITypeInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo2)