# IMFMediaSourceEx::GetSourceAttributes

## Description

Gets an attribute store for the media source.

## Parameters

### `ppAttributes` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | The media source does not support source-level attributes. |

## Remarks

Use the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) pointer to get or set attributes that apply to the entire source. For stream-level attributes, use the [IMFMediaSourceEx::GetStreamAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasourceex-getstreamattributes) method instead.

## See also

[IMFMediaSourceEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasourceex)