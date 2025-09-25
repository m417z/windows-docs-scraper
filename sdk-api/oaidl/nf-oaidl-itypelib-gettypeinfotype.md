# ITypeLib::GetTypeInfoType

## Description

Retrieves the type of a type description.

## Parameters

### `index` [in]

The index of the type description within the type library.

### `pTKind` [out]

The [TYPEKIND](https://learn.microsoft.com/windows/desktop/api/oaidl/ne-oaidl-typekind) enumeration value for the type description.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TYPE_E_ELEMENTNOTFOUND** | The *index* parameter is outside the range of to [GetTypeInfoCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-gettypeinfocount) - 1. |

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)