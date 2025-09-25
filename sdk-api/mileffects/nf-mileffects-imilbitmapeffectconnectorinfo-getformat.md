# IMILBitmapEffectConnectorInfo::GetFormat

## Description

Retrieves the pixel format for the given pin.

## Parameters

### `ulIndex` [in]

Type: **ULONG**

A zero based index value indicating the pin to retrieve the pixel format.

### `pFormat` [out, retval]

Type: **WICPixelFormatGUID***

When this method returns, contains the pixel format of the given pin.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.