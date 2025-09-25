# IWiaPropertyStorage::GetPropertyStream

## Description

The **IWiaPropertyStorage::GetPropertyStream** method retrieves the property stream of an item.

## Parameters

### `pCompatibilityId` [out]

Type: **GUID***

Receives a unique identifier for a set of property values.

### `ppIStream` [out]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

Pointer to a stream that receives the item properties. For more information, see [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications use this method to get a snapshot of the current properties of an item. These are subsequently restored by calling [IWiaPropertyStorage::SetPropertyStream](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiapropertystorage-setpropertystream).

Applications can use the *pCompatibilityID* parameter to check if a device supports a specific set of property values before attempting to write these values to the device.

When it is finished using the item's property stream, the application must release it.

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IWiaPropertyStorage](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage)