# ISdoCollection::Add

## Description

The
**Add** method adds an item to the Server Data Objects (SDO) collection.

## Parameters

### `bstrName` [in]

Specifies the name of the SDO Object. This parameter may be **NULL**.

### `ppItem` [in, out]

Pointer to an **IDispatch** interface pointer for the Item to add. This parameter must not be **NULL**.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

If you specify the name of the object to add, ensure that the name is unique by calling
[ISdoCollection::IsNameUnique](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdocollection-isnameunique).

If the *bstrName* parameter is not specified, **ISdoCollection::Add** obtains it from the object specified by the *ppItem* parameter.

## See also

[Adding an Object to a Collection](https://learn.microsoft.com/windows/desktop/Nps/sdo-adding-an-object-to-a-collection)

[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)

[IASCOMMONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iascommonproperties)

[ISdoCollection](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdocollection)

[ISdoCollection::IsNameUnique](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdocollection-isnameunique)