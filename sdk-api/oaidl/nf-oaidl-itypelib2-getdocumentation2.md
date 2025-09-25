# ITypeLib2::GetDocumentation2

## Description

Retrieves the library's documentation string, the complete Help file name and path, the localization context to use, and the context ID for the library Help topic in the Help file.

## Parameters

### `index` [in]

The index of the type description whose documentation is to be returned. If *index* is -1, then the documentation for the library is returned.

### `lcid` [in]

The locale identifier.

### `pbstrHelpString` [out]

The name of the specified item. If the caller does not need the item name, then *pbstrHelpString* can be null

### `pdwHelpStringContext` [out]

The Help localization context. If the caller does not need the Help context, then it can be null.

### `pbstrHelpStringDll` [out]

The fully qualified name of the file containing the DLL used for Help file. If the caller does not need the file name, then it can be null.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |

## Remarks

Gets information at the type library level. The caller should free the BSTR parameters.

This function will call **_DLLGetDocumentation** in the specified DLL to retrieve the desired Help string, if there is a Help string context for this item. If no Help string context exists or an error occurs, then it will defer to the [GetDocumentation](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-getdocumentation) method and return the associated documentation string.

## See also

[ITypeLib2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib2)