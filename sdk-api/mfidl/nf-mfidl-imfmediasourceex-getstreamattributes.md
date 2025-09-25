# IMFMediaSourceEx::GetStreamAttributes

## Description

Gets an attribute store for a stream on the media source.

## Parameters

### `dwStreamIdentifier` [in]

The identifier of the stream. To get the identifier, call [IMFStreamDescriptor::GetStreamIdentifier](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamdescriptor-getstreamidentifier) on the stream descriptor.

### `ppAttributes` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | The media source does not support stream-level attributes. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |

## Remarks

Use the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) pointer to get or set attributes that apply to the specified stream. For attributes that apply to the entire source, use the [IMFMediaSourceEx::GetSourceAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasourceex-getsourceattributes) method instead.

## See also

[IMFMediaSourceEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasourceex)