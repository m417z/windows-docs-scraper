# IWICBitmapCodecInfo::GetFileExtensions

## Description

Retrieves a comma delimited list of the file name extensions associated with the codec.

## Parameters

### `cchFileExtensions` [in]

Type: **UINT**

The size of the file name extension buffer. Use `0` on first call to determine needed buffer size.

### `wzFileExtensions` [in, out]

Type: **WCHAR***

Receives a comma delimited list of file name extensions associated with the codec. Use `NULL` on first call to determine needed buffer size.

### `pcchActual` [in, out]

Type: **UINT***

The actual buffer size needed to retrieve all file name extensions associated with the codec.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default extension for an image encoder is the first item in the list of returned extensions.

The usage pattern for this method is a two call process.
The first call retrieves the buffer size needed to retrieve the full color management version number by calling it with *cchFileExtensions* set to `0` and *wzFileExtensions* set to `NULL`.
This call sets *pcchActual* to the buffer size needed.
Once the needed buffer size is determined, a second **GetFileExtensions** call with *cchFileExtensions* set to the buffer size and *wzFileExtensions* set to a buffer of the appropriate size will retrieve the pixel formats.