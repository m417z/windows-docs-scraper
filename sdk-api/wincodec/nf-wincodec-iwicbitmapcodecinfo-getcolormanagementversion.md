# IWICBitmapCodecInfo::GetColorManagementVersion

## Description

Retrieves the color management version number the codec supports.

## Parameters

### `cchColorManagementVersion` [in]

Type: **UINT**

The size of the version buffer. Use `0` on first call to determine needed buffer size.

### `wzColorManagementVersion` [in, out]

Type: **WCHAR***

Receives the color management version number. Use `NULL` on first call to determine needed buffer size.

### `pcchActual` [in, out]

Type: **UINT***

The actual buffer size needed to retrieve the full color management version number.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The usage pattern for this method is a two call process.
The first call retrieves the buffer size needed to retrieve the full color management version number by calling it with *cchColorManagementVersion* set to `0` and *wzColorManagementVersion* set to `NULL`.
This call sets *pcchActual* to the buffer size needed.
Once the needed buffer size is determined, a second **GetColorManagementVersion** call with *cchColorManagementVersion* set to the buffer size and *wzColorManagementVersion* set to a buffer of the appropriate size will retrieve the pixel formats.