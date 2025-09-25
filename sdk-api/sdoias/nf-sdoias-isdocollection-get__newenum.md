# ISdoCollection::get__NewEnum

## Description

The
**get__NewEnum** method retrieves an
[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface for a Server Data Objects (SDO) collection.

## Parameters

### `ppEnumVARIANT` [out]

Pointer to an
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer. On successful return the **IUnknown** interface pointer, points to an
[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface.

This parameter must not be **NULL**.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Initialize the SDO before calling this method.

**Note** Two underscores are used between "get" and "NewEnum" in the name of this method.

## See also

[ISdoCollection](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdocollection)