# IWICBitmapCodecInfo::MatchesMimeType

## Description

Retrieves a value indicating whether the given mime type matches the mime type of the codec.

## Parameters

### `wzMimeType` [in]

Type: **LPCWSTR**

The mime type to compare.

### `pfMatches` [out]

Type: **BOOL***

Receives **TRUE** if the mime types match; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_NOTIMPL** | The codec does not implement this method. |

## Remarks

**Note** The Windows provided codecs do not implement this method and return E_NOTIMPL.