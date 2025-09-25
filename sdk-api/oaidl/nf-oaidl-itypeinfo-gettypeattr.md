# ITypeInfo::GetTypeAttr

## Description

Retrieves a TYPEATTR structure that contains the attributes of the type description.

## Parameters

### `ppTypeAttr` [out]

The attributes of this type description.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

To free the TYPEATTR structure, use [ITypeInfo::ReleaseTypeAttr](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-releasetypeattr).

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)