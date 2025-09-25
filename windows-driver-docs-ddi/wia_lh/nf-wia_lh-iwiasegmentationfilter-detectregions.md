## Description

The **IWiaSegmentationFilter::DetectRegions** method determines the subregions of an image laid out on the flatbed platen so that each subregion can be acquired into a separate image item.

## Parameters

### `lFlags` [in]

Currently unused. Should be set to zero.

### `pInputStream` [in, optional]

Specifies a pointer to the [**IStream**](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream) preview image.

### `pWiaItem2` [in, optional]

Specifies a pointer to the [**IWiaItem2**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2) item for which *pInputStream* was acquired. The segmentation filter creates child items for this item.

## Return value

Returns S_OK if successful, or a standard COM error value otherwise.

## Remarks

This method determines the subregions of the image represented by *pInputStream*. For each subregion that it detects, it creates a child item for the **IWiaItem2**] item pointed to by the *pWiaItem2* parameter. For each child item, the segmentation filter must set values for the bounding rectangle of the area to scan, using the following WIA scanner item properties:

[WIA_IPS_XPOS](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-xpos)

[WIA_IPS_YPOS](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-ypos)

[WIA_IPS_XEXTENT](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-xextent)

[WIA_IPS_YEXTENT](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-yextent)

A more advanced filter might also require other scanner item properties, such as [WIA_IPS_DESKEW_X](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-deskew-x) and [WIA_IPS_DESKEW_Y](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-deskew-y), if the driver supports deskewing.

If an application calls **IWiaSegmentationFilter::DetectRegions** more than once, the application must first delete the child items created by the last call to the **IWiaSegmentationFilter::DetectRegions** method.

If an application changes any properties into *pWiaItem2*, between acquiring the image into *pInputStream* and its call to **IWiaSegmentationFilter::DetectRegions**, the original property settings (the property settings the item had when the stream was acquired) must be restored. This can be done using [**IWiaPropertyStorage::GetPropertyStream**](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiapropertystorage-getpropertystream) and [**IWiaPropertyStorage::SetPropertyStream**](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiapropertystorage-setpropertystream).

The application must reset the **IStream** preview if its call passes the same stream into the segmentation filter more than once. The application must also reset the stream after the initial download and before calling **IWiaSegmentationFilter::DetectRegions**.

## See also

[**IStream**](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream)

[**IWiaItem2**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2)

[**IWiaPropertyStorage**](https://learn.microsoft.com/windows/win32/api/wia_xp/nn-wia_xp-iwiapropertystorage)