# ITypeInfo::GetIDsOfNames

## Description

Maps between member names and member IDs, and parameter names and parameter IDs.

## Parameters

### `rgszNames` [in]

An array of names to be mapped.

### `cNames` [in]

The count of the names to be mapped.

### `pMemId` [out]

Caller-allocated array in which name mappings are placed.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The function [GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) maps the name of a member (**rgszNames**[0]) and its parameters (**rgszNames**[1] ...**rgszNames**[**cNames**- 1]) to the ID of the member (**pMemId**[0]), and to the IDs of the specified parameters (**pMemId**[1] ... **pMemId**[**cNames**- 1]). The IDs of parameters are 0 for the first parameter in the member function's argument list, 1 for the second, and so on.

If the type description inherits from another type description, this function is recursive to the base type description, if necessary, to find the item with the requested member ID.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)