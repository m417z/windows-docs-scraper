# IWICImagingFactory::CreateDecoder

## Description

Creates a new instance of [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder).

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

### `pguidVendor` [in]

Type: **const GUID***

The GUID for the preferred encoder vendor.

| Value | Meaning |
| --- | --- |
| NULL | No preferred codec vendor. |
| GUID_VendorMicrosoft | Prefer to use Microsoft encoder. |
| GUID_VendorMicrosoftBuiltIn | Prefer to use the native Microsoft encoder. |

### `ppIDecoder` [out, retval]

Type: **[IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder)****

A pointer that receives a pointer to a new [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder). You must initialize this **IWICBitmapDecoder** on a stream using the [Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapdecoder-initialize) method later.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Other values may be available for both *guidContainerFormat* and *pguidVendor* depending on the installed WIC-enabled encoders.
The values listed are those that are natively supported by the operating system.

## See also

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)

[WIC GUIDs and CLSIDs](https://learn.microsoft.com/windows/desktop/wic/-wic-guids-clsids)