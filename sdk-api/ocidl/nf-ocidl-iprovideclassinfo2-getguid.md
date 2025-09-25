# IProvideClassInfo2::GetGUID

## Description

Retrieves the specified GUID for the object.

## Parameters

### `dwGuidKind` [in]

The GUID type. Possible values are from the [GUIDKIND](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-guidkind) enumeration.

### `pGUID` [out]

A pointer to a variable that receives the GUID.

## Return value

This method can return the standard return values E_INVALIDARG, E_UNEXPECTED, E_POINTER, and S_OK.

## See also

[IProvideClassInfo2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iprovideclassinfo2)