# ITypeInfo::GetMops

## Description

Retrieves marshaling information.

## Parameters

### `memid` [in]

The member ID that indicates which marshaling information is needed.

### `pBstrMops` [out]

The opcode string used in marshaling the fields of the structure described by the referenced type description, or null if there is no information to return.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

If the passed-in member ID is MEMBERID_NIL, the function returns the opcode string for marshaling the fields of the structure described by the type description. Otherwise, it returns the opcode string for marshaling the function specified by the index.

If the type description inherits from another type description, this function recurses on the base type description, if necessary, to find the item with the requested member ID.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)