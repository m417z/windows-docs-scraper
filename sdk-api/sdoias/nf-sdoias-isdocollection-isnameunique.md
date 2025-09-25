# ISdoCollection::IsNameUnique

## Description

The
**IsNameUnique** method tests whether the specified name is unique in the collection.

## Parameters

### `bstrName` [in]

Specifies the name to test.

### `pBool` [out]

Pointer to a **VARIANT** that specifies whether the name is unique. The returned value is **VARIANT_TRUE** if the name is unique, **VARIANT_FALSE** otherwise.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Neither of the parameters may be **NULL**.

## See also

[Adding an Object to a Collection](https://learn.microsoft.com/windows/desktop/Nps/sdo-adding-an-object-to-a-collection)

[IASCOMMONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iascommonproperties)

[ISdoCollection](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdocollection)

[ISdoCollection::Add](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdocollection-add)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)