# IWICBitmapCodecInfo::GetDeviceModels

## Description

Retrieves a comma delimited list of device models associated with the codec.

## Parameters

### `cchDeviceModels` [in]

Type: **UINT**

The size of the device models buffer. Use `0` on first call to determine needed buffer size.

### `wzDeviceModels` [in, out]

Type: **WCHAR***

Receives a comma delimited list of device model names associated with the codec. Use `NULL` on first call to determine needed buffer size.

### `pcchActual` [in, out]

Type: **UINT***

The actual buffer size needed to retrieve all of the device model names.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The usage pattern for this method is a two call process.
The first call retrieves the buffer size needed to retrieve the full color management version number by calling it with *cchDeviceModels* set to `0` and *wzDeviceModels* set to `NULL`.
This call sets *pcchActual* to the buffer size needed.
Once the needed buffer size is determined, a second **GetDeviceModels** call with *cchDeviceModels* set to the buffer size and *wzDeviceModels* set to a buffer of the appropriate size will retrieve the pixel formats.