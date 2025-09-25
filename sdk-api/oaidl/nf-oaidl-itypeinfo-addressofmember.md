# ITypeInfo::AddressOfMember

## Description

Retrieves the addresses of static functions or variables, such as those defined in a DLL.

## Parameters

### `memid` [in]

The member ID of the static member whose address is to be retrieved. The member ID is defined by the DISPID.

### `invKind` [in]

Indicates whether the member is a property, and if so, what kind.

### `ppv` [out]

The static member.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The addresses are valid until the caller releases its reference to the type description. The *invKind* parameter can be ignored unless the address of a property function is being requested.

If the type description inherits from another type description, this function is recursive to the base type description, if necessary, to find the item with the requested member ID.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)