# IWiaPropertyStorage::SetPropertyStream

## Description

The **IWiaPropertyStorage::SetPropertyStream** sets the property stream of an item in the tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects of a Windows Image Acquisition (WIA) hardware device.

## Parameters

### `pCompatibilityId` [in]

Type: **GUID***

Specifies a unique identifier for a set of property values.

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to the property stream that is used to set the current item's property stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications use the *pCompatibilityID* parameter to check whether a device supports a specific set of property values before attempting to write these values to the device.

Set *pIStream* to **NULL** to check whether the device driver accepts the CompatibilityID specified by *pCompatibilityID*.

If the application obtained the property stream of the item using the [IWiaPropertyStorage::GetPropertyStream](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiapropertystorage-getpropertystream) method, the application must release it. For more information, see [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IWiaPropertyStorage](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage)