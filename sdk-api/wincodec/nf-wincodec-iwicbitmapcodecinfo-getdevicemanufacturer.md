# IWICBitmapCodecInfo::GetDeviceManufacturer

## Description

Retrieves the name of the device manufacture associated with the codec.

## Parameters

### `cchDeviceManufacturer` [in]

Type: **UINT**

The size of the device manufacture's name. Use `0` on first call to determine needed buffer size.

### `wzDeviceManufacturer` [in, out]

Type: **WCHAR***

Receives the device manufacture's name. Use `NULL` on first call to determine needed buffer size.

### `pcchActual` [out]

Type: **UINT***

The actual buffer size needed to retrieve the device manufacture's name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The usage pattern for this method is a two call process.
The first call retrieves the buffer size needed to retrieve the full color management version number by calling it with *cchDeviceManufacturer* set to `0` and *wzDeviceManufacturer* set to `NULL`.
This call sets *pcchActual* to the buffer size needed.
Once the needed buffer size is determined, a second **GetDeviceManufacturer** call with *cchDeviceManufacturer* set to the buffer size and *wzDeviceManufacturer* set to a buffer of the appropriate size will retrieve the pixel formats.