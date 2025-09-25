# IWICImagingFactory::CreateEncoder

## Description

Creates a new instance of the [IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder) class.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The GUID for the desired container format.

| Value | Meaning |
| --- | --- |
| GUID_ContainerFormatBmp | The BMP container format GUID. |
| GUID_ContainerFormatPng | The PNG container format GUID. |
| GUID_ContainerFormatIco | The ICO container format GUID. |
| GUID_ContainerFormatJpeg | The JPEG container format GUID. |
| GUID_ContainerFormatTiff | The TIFF container format GUID. |
| GUID_ContainerFormatGif | The GIF container format GUID. |
| GUID_ContainerFormatWmp | The HD Photo container format GUID. |

### `pguidVendor` [in, optional]

Type: **const GUID***

The GUID for the preferred encoder vendor.

| Value | Meaning |
| --- | --- |
| NULL | No preferred codec vendor. |
| GUID_VendorMicrosoft | Prefer to use Microsoft encoder. |
| GUID_VendorMicrosoftBuiltIn | Prefer to use the native Microsoft encoder. |

### `ppIEncoder` [out, retval]

Type: **[IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)****

A pointer that receives a pointer to a new [IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Other values may be available for both *guidContainerFormat* and *pguidVendor* depending on the installed WIC-enabled encoders.
The values listed are those that are natively supported by the operating system.

## See also

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)

[WIC GUIDs and CLSIDs](https://learn.microsoft.com/windows/desktop/wic/-wic-guids-clsids)