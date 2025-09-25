# ICreateTypeInfo::SetGuid

## Description

Sets the globally unique identifier (GUID) associated with the type description.

## Parameters

### `guid` [in]

The globally unique ID to be associated with the type description.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_ACCESSDENIED** | Cannot write to the destination. |
| **STG_E_INSUFFICIENTMEMORY** | Insufficient memory to complete the operation. |

## Remarks

For an interface, this is an interface ID (IID); for a coclass, it is a class ID (CLSID). For information on GUIDs, see [Type Libraries and the Object Description Language](https://learn.microsoft.com/previous-versions/windows/desktop/automat/type-libraries-and-the-object-description-language).

## See also

[ICreateTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypeinfo)