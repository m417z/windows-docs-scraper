# IWICFormatConverterInfo::GetPixelFormats

## Description

Retrieves a list of GUIDs that signify which pixel formats the converter supports.

## Parameters

### `cFormats` [in]

Type: **UINT**

The size of the *pPixelFormatGUIDs* array.

### `pPixelFormatGUIDs` [in, out]

Type: **WICPixelFormatGUID***

Pointer to a GUID array that receives the pixel formats the converter supports.

### `pcActual` [out]

Type: **UINT***

The actual array size needed to retrieve all pixel formats supported by the converter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The format converter does not necessarily guarantee symmetricality with respect to conversion; that is, a converter may be able to convert FROM a particular format without actually being able to convert TO a particular format. In order to test symmetricality, use [CanConvert](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicformatconverter-canconvert).

To determine the number of pixel formats a converter can handle, set *cFormats* to `0` and *pPixelFormatGUIDs* to `NULL`. The converter will fill *pcActual* with the number of formats supported by that converter.