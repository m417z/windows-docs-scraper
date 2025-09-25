# ICreateTypeLib::SetHelpFileName

## Description

Sets the name of the Help file.

## Parameters

### `szHelpFileName` [in]

The name of the Help file for the library.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_INVALIDSTATE** | The state of the type library is not valid for this operation. |

## Remarks

Each type library can reference a single Help file.

The [GetDocumentation](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-getdocumentation) method of the created [ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib) returns a fully qualified path for the Help file, which is formed by appending the name passed into *szHelpFileName* to the registered Help directory for the type library. The Help directory is registered under:

\TYPELIB\<guid of library>\<Major.Minor version >\HELPDIR

## See also

[ICreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib)