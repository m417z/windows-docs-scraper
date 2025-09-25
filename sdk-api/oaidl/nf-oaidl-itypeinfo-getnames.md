# ITypeInfo::GetNames

## Description

Retrieves the variable with the specified member ID or the name of the property or method and the parameters that correspond to the specified function ID.

## Parameters

### `memid` [in]

The ID of the member whose name (or names) is to be returned.

### `rgBstrNames` [out]

The caller-allocated array. On return, each of the elements contains the name (or names) associated with the member.

### `cMaxNames` [in]

The length of the passed-in *rgBstrNames* array.

### `pcNames` [out]

The number of names in the *rgBstrNames* array.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The caller must release the returned BSTR array.

If the member ID identifies a property that is implemented with property functions, the property name is returned. For property get functions, the names of the function and its parameters are always returned.

For property put and put reference functions, the right side of the assignment is unnamed. If *cMaxNames* is less than is required to return all of the names of the parameters of a function, then only the names of the first *cMaxNames* - 1 parameters are returned. The names of the parameters are returned in the array in the same order that they appear elsewhere in the interface (for example, the same order in the parameter array associated with the FUNCDESC enumeration).

If the type description inherits from another type description, this function is recursive to the base type description, if necessary, to find the item with the requested member ID.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)