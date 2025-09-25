# IMFSinkWriter::SetInputMediaType

## Description

Sets the input format for a stream on the sink writer.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream. The index is received by the *pdwStreamIndex* parameter of the [IMFSinkWriter::AddStream](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-addstream) method.

### `pInputMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a media type. The media type specifies the input format.

### `pEncodingParameters` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store. Use the attribute store to configure the encoder. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDMEDIATYPE**** | The underlying media sink does not support the format, no conversion is possible, or a dynamic format change is not possible. |
| ****MF_E_INVALIDSTREAMNUMBER**** | The *dwStreamIndex* parameter is invalid. |
| ****MF_E_TOPO_CODEC_NOT_FOUND**** | Could not find an encoder for the encoded format. |

## Remarks

The input format does not have to match the target format that is written to the media sink. If the formats do not match, the method attempts to load an encoder that can encode from the input format to the target format.

After streaming begins—that is, after the first call to [IMFSinkWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-writesample)—you can call this method at any time to change the input format. However, the underlying encoder and media sink must support dynamic format changes.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)