# IWICBitmapCodecInfo::GetPixelFormats

## Description

Retrieves the pixel formats the codec supports.

## Parameters

### `cFormats` [in]

Type: **UINT**

The size of the *pguidPixelFormats* array. Use `0` on first call to determine the needed array size.

### `pguidPixelFormats` [in, out]

Type: **GUID***

Receives the supported pixel formats. Use `NULL` on first call to determine needed array size.

### `pcActual` [out]

Type: **UINT***

The array size needed to retrieve all supported pixel formats.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The usage pattern for this method is a two call process.
The first call retrieves the array size needed to retrieve all the supported pixel formats by calling it with *cFormats* set to `0` and *pguidPixelFormats* set to `NULL`.
This call sets *pcActual* to the array size needed.
Once the needed array size is determined, a second **GetPixelFormats** call with *pguidPixelFormats* set to an array of the appropriate size will retrieve the pixel formats.