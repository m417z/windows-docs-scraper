# ITypeInfo::GetRefTypeOfImplType

## Description

If a type description describes a COM class, it retrieves the type description of the implemented interface types. For an interface, **GetRefTypeOfImplType** returns the type information for inherited interfaces, if any exist.

## Parameters

### `index` [in]

The index of the implemented type whose handle is returned. The valid range is 0 to the **cImplTypes** field in the TYPEATTR structure.

### `pRefType` [out]

A handle for the implemented interface (if any). This handle can be passed to [ITypeInfo::GetRefTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-getreftypeinfo) to get the type description.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **TYPE_E_ELEMENTNOTFOUND** | Passed index is outside the range 0 to 1 less than the number of implemented interfaces. |

## Remarks

If the TKIND_DISPATCH type description is for a dual interface, the TKIND_INTERFACE type description can be obtained by calling **GetRefTypeOfImplType** with an *index* of –1, and by passing the returned *pRefTypehandle* to [GetRefTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-getreftypeinfo) to retrieve the type information.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)