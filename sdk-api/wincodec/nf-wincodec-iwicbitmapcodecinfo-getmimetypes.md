# IWICBitmapCodecInfo::GetMimeTypes

## Description

Retrieves a comma delimited sequence of mime types associated with the codec.

## Parameters

### `cchMimeTypes` [in]

Type: **UINT**

The size of the mime types buffer. Use `0` on first call to determine needed buffer size.

### `wzMimeTypes` [out]

Type: **WCHAR***

Receives the mime types associated with the codec. Use `NULL` on first call to determine needed buffer size.

### `pcchActual` [out]

Type: **UINT***

The actual buffer size needed to retrieve all mime types associated with the codec.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The usage pattern for this method is a two call process.
The first call retrieves the buffer size needed to retrieve the full color management version number by calling it with *cchMimeTypes* set to `0` and *wzMimeTypes* set to `NULL`.
This call sets *pcchActual* to the buffer size needed.
Once the needed buffer size is determined, a second **GetMimeTypes** call with *cchMimeTypes* set to the buffer size and *wzMimeTypes* set to a buffer of the appropriate size will retrieve the pixel formats.