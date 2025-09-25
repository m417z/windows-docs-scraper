# ISdoCollection::Item

## Description

The
**Item** method retrieves the specified item from the collection.

## Parameters

### `Name` [in]

Pointer to a
[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant). Store the name of the object in a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) in this **VARIANT**.

### `pItem` [out]

Pointer to an interface pointer that receives the address of an
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface for the object.

## Return value

If the method succeeds the return value is **S_OK**.

If the object is not found in the collection, the return value is **DISP_E_MEMBERNOTFOUND**.

Otherwise, if the method fails, the return value is one of the following error codes.

## Remarks

Neither of the parameters can be **NULL**.

## See also

[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)

[IASCOMMONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iascommonproperties)

[ISdoCollection](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdocollection)

[Retrieving an Object from a Collection](https://learn.microsoft.com/windows/desktop/Nps/sdo-retrieving-an-object-from-a-collection)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)