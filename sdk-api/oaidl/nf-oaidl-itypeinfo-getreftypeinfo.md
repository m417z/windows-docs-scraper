# ITypeInfo::GetRefTypeInfo

## Description

If a type description references other type descriptions, it retrieves the referenced type descriptions.

## Parameters

### `hRefType` [in]

A handle to the referenced type description to return.

### `ppTInfo` [out]

The referenced type description.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

On return, the second parameter contains a pointer to a pointer to a type description that is referenced by this type description. A type description must have a reference to each type description that occurs as the type of any of its variables, function parameters, or function return types. For example, if the type of a data member is a record type, the type description for that data member contains the *hRefType* of a referenced type description. To get a pointer to the type description, the reference is passed to **GetRefTypeInfo**.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)